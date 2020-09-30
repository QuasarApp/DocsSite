//#
//# Copyright (C) 2020-2020 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#include "correnthostimageprovider.h"
#include <cassert>
#include <quasarapp.h>
#include <fetchapi.h>

namespace BaseFront {

CorrentHostImageProvider::CorrentHostImageProvider() {

}

CorrentHostImageProvider::~CorrentHostImageProvider() {
}

QQuickImageResponse *CorrentHostImageProvider::requestImageResponse(
        const QString &id, const QSize &requestedSize) {

    AsyncImageResponse *response = new AsyncImageResponse(this, id, requestedSize);
    response->run();

    return response;
}

const QImage *CorrentHostImageProvider::fromCache(const QString &id) {
    if (!_cache.contains(id)) {
        return nullptr;
    }
    return &_cache[id];
}

void CorrentHostImageProvider::addToCache(const QString &id, const QImage &img) {
    _cache[id] = img;
}

AsyncImageResponse::AsyncImageResponse(CorrentHostImageProvider * provider,
                                       const QString &id, const QSize &requestedSize)
    :
      m_fetch(new FetchAPI()),
      m_parentProvider(provider),
      m_id(id),
      m_requestedSize(requestedSize) {

    setAutoDelete(false);
}

AsyncImageResponse::~AsyncImageResponse() {
    delete m_fetch;
}

QQuickTextureFactory *AsyncImageResponse::textureFactory() const {
    return QQuickTextureFactory::textureFactoryForImage(m_image);
}

void AsyncImageResponse::run() {


    auto handleSuccessful = [this](const QString& id, const QByteArray& data) {
        m_image = QImage::fromData(data);

        if (m_parentProvider) {
            m_parentProvider->addToCache(id, m_image);
        }

        emit finished();
    };

    auto handleFail = [this](const QString&, const QString&) {
        cancel();
    };

    connect(m_fetch, &FetchAPI::sigFinished, handleSuccessful);
    connect(m_fetch, &FetchAPI::sigError, handleFail);

    if (m_parentProvider) {
        if (auto img = m_parentProvider->fromCache(m_id)) {
            m_image = *img;
            emit finished();
            return;
        }
    }

    m_fetch->Get(m_id);

}

}
