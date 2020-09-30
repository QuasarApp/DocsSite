//
// Copyright (C) 2020-2020 QuasarApp.
// Distributed under the lgplv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "fetchapi.h"
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

#ifdef Q_OS_WASM
void downloadSucceeded(emscripten_fetch_t *fetch) {
    auto fetchAPI = static_cast<FetchAPI*>(fetch->userData);
    QByteArray data(reinterpret_cast<const char*>(fetch->data),
                   fetch->numBytes);

    emit fetchAPI->sigFinished(QString("%0").arg(fetch->url), data);

    emscripten_fetch_close(fetch); // Free data associated with the fetch.
};

void downloadFailed(emscripten_fetch_t *fetch) {

    QuasarAppUtils::Params::log(QString("Downloading %0 failed, HTTP failure status code: %1.\n").
                                arg(fetch->url).arg(fetch->status),
                                QuasarAppUtils::Error);

    emscripten_fetch_close(fetch); // Also free data on failure.

    auto fetchAPI = static_cast<FetchAPI*>(fetch->userData);
    emit fetchAPI->sigError(QString("%0").arg(fetch->url),
                           QString("Downloading %0 failed, HTTP failure status code: %1.\n").
                           arg(fetch->url).arg(fetch->status));

};
#endif

FetchAPI::FetchAPI(QObject *parent):
    QObject(parent) {
#ifndef Q_OS_WASM
    m_manager = new QNetworkAccessManager;
#endif
}

void FetchAPI::Get(const QString &url) {

#ifdef Q_OS_WASM
    emscripten_fetch_attr_t attr;
    emscripten_fetch_attr_init(&attr);
    attr.userData = this;
    strcpy(attr.requestMethod, "GET");
    attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
    attr.onsuccess = downloadSucceeded;
    attr.onerror = downloadFailed;

    auto stdString = url.toStdString();
    emscripten_fetch(&attr, stdString.c_str());
#else
    QNetworkRequest request(url);

    m_manager->get(request);

    auto handleRequest= [this](QNetworkReply *reply) {

        if (reply->error() != QNetworkReply::NoError) {
            QuasarAppUtils::Params::log(reply->errorString(),
                                        QuasarAppUtils::Error);

            emit sigError(reply->url().toString(), reply->errorString());
        }

        auto data = reply->readAll();
        emit sigFinished(reply->url().toString(), data);

    };

    connect(m_manager, &QNetworkAccessManager::finished, handleRequest);
#endif
}

}


