//#
//# Copyright (C) 2020-2020 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#include "correnthostimageprovider.h"

#include <quasarapp.h>

#ifdef Q_OS_WASM
#include <emscripten/fetch.h>
#include <string>
#else
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
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
    :
      #ifndef Q_OS_WASM
      m_manager(new QNetworkAccessManager),
      #endif
      m_id(id),
      m_requestedSize(requestedSize)  {
    setAutoDelete(false);
}

AsyncImageResponse::~AsyncImageResponse() {
#ifndef Q_OS_WASM
    delete m_manager;
#endif
}

QQuickTextureFactory *AsyncImageResponse::textureFactory() const {
    return QQuickTextureFactory::textureFactoryForImage(m_image);
}

#ifdef Q_OS_WASM
static void *response = nullptr;
#endif

void AsyncImageResponse::run() {


#ifdef Q_OS_WASM
    response = this;
    auto downloadSucceeded = [](emscripten_fetch_t *fetch) {
        auto resp = static_cast<AsyncImageResponse*>(response);
        resp->m_image = QImage::fromData(reinterpret_cast<const unsigned char*>(fetch->data),
                                         fetch->numBytes);

        if (resp->m_requestedSize.isValid())
            resp->m_image = resp->m_image.scaled(resp->m_requestedSize);

        emit resp->finished();

        emscripten_fetch_close(fetch); // Free data associated with the fetch.
    };

    auto downloadFailed = [](emscripten_fetch_t *fetch) {

        QuasarAppUtils::Params::log(QString("Downloading %0 failed, HTTP failure status code: %1.\n").
                                    arg(fetch->url).arg(fetch->status),
                                    QuasarAppUtils::Error);

        emscripten_fetch_close(fetch); // Also free data on failure.

        auto resp = static_cast<AsyncImageResponse*>(response);
        resp->cancel();
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
    QNetworkRequest request;

    m_manager->get(request);

    auto handleRequest= [this](QNetworkReply *reply) {

        if (reply->error() != QNetworkReply::NoError) {
            QuasarAppUtils::Params::log(reply->errorString(),
                                        QuasarAppUtils::Error);

            cancel();
        }

        auto data = reply->readAll();
        m_image = QImage::fromData(data);

        if (m_requestedSize.isValid())
            m_image = m_image.scaled(m_requestedSize);

        emit finished();

    };

    connect(m_manager, &QNetworkAccessManager::finished, handleRequest);
#endif

}

}
