//
// Copyright (C) 2020-2020 QuasarApp.
// Distributed under the lgplv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//


#ifndef FETCHAPI_H
#define FETCHAPI_H

#include "BaseFront_global.h"

#include <QObject>
class QNetworkAccessManager;

namespace BaseFront {

class BASEFRONT_LIBRARYSHARED_EXPORT FetchAPI: public QObject
{
    Q_OBJECT
public:
    FetchAPI(QObject *parent = nullptr);
    void Get(const QString& url);

signals:
    void sigFinished(const QString& requestUrl, const QByteArray& data);
    void sigError(const QString& requestUrl, const QString& error);

private:
#ifndef Q_OS_WASM
private:
    QNetworkAccessManager *m_manager = nullptr;
#endif
};
}
#endif // FETCHAPI_H
