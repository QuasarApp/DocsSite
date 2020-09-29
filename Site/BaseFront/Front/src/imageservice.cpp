//
// Copyright (C) 2020-2020 QuasarApp.
// Distributed under the lgplv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "imageservice.h"

#include <fetchapi.h>
namespace BaseFront {

ImageService::ImageService(QObject *parent):
    QObject(parent) {
    _fetchAPI = new FetchAPI(this);
}

ImageService::~ImageService() {
    delete _fetchAPI;
}

const QImage &ImageService::getImage(const QString &img) const {

}
}
