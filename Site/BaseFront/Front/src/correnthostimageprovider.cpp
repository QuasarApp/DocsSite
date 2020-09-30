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

    AsyncImageResponse *response = new AsyncImageResponse(id, requestedSize);
    response->run();

    return response;
}

AsyncImageResponse::AsyncImageResponse(const QString &id, const QSize &requestedSize)
    :
      m_fetch(new FetchAPI()),
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

    m_fetch->Get(m_id);

    auto handleSuccessful = [this](const QString&, const QByteArray& data) {
        m_image = QImage::fromData(data);
        emit finished();
    };

    auto handleFail = [this](const QString&, const QString&) {
        cancel();
    };

    connect(m_fetch, &FetchAPI::sigFinished, handleSuccessful);
    connect(m_fetch, &FetchAPI::sigError, handleFail);

}

}
