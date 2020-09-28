#include "correnthostimageprovider.h"
#include <string>
#include <functional>

#ifdef WASM32_BUILD
#include <emscripten/fetch.h>
#endif

namespace BaseFront {

CorrentHostImageProvider::CorrentHostImageProvider() {
}

CorrentHostImageProvider::~CorrentHostImageProvider() {
}

QQuickImageResponse *CorrentHostImageProvider::requestImageResponse(
        const QString &id, const QSize &requestedSize) {

    AsyncImageResponse *response = new AsyncImageResponse(id, requestedSize);

    response->run();

    return response;
}

AsyncImageResponse::AsyncImageResponse(const QString &id, const QSize &requestedSize)
    : m_id(id), m_requestedSize(requestedSize) {
    setAutoDelete(false);
}

QQuickTextureFactory *AsyncImageResponse::textureFactory() const {
    return QQuickTextureFactory::textureFactoryForImage(m_image);
}

#ifdef WASM32_BUILD
static void * tmpPTR = nullptr;
#endif

void AsyncImageResponse::run() {
#ifdef WASM32_BUILD
    tmpPTR = this;
    auto downloadSucceeded = [](emscripten_fetch_t *fetch){
        auto resp = reinterpret_cast<AsyncImageResponse*>(tmpPTR);
        resp->m_image = QImage::fromData(reinterpret_cast<const unsigned char *>(fetch->data), fetch->numBytes);

        if (resp->m_requestedSize.isValid())
            resp->m_image = resp->m_image.scaled(resp->m_requestedSize);

        emit resp->finished();

        emscripten_fetch_close(fetch); // Free data associated with the fetch.
    };

    auto downloadFailed = [](emscripten_fetch_t *fetch){
        emscripten_fetch_close(fetch); // Also free data on failure.
    };

    emscripten_fetch_attr_t attr;
    emscripten_fetch_attr_init(&attr);
    strcpy(attr.requestMethod, "GET");
    attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
    attr.onsuccess = downloadSucceeded;
    attr.onerror = downloadFailed;
    auto stdString = m_id.toStdString();
    emscripten_fetch(&attr, stdString.c_str());
#else
    cancel();
#endif



}

}
