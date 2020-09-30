//
// Copyright (C) 2020-2020 QuasarApp.
// Distributed under the lgplv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//


#ifndef CORRENTHOSTIMAGEPROVIDER_H
#define CORRENTHOSTIMAGEPROVIDER_H

#include <QQuickAsyncImageProvider>
#include <QRunnable>
#include "BaseFront_global.h"

class QNetworkAccessManager;

namespace BaseFront {
class FetchAPI;

class BASEFRONT_LIBRARYSHARED_EXPORT AsyncImageResponse : public QQuickImageResponse, public QRunnable
{
public:
    AsyncImageResponse(const QString &id, const QSize &requestedSize);
    ~AsyncImageResponse() override;
    QQuickTextureFactory *textureFactory() const override;

    void run() override;

    FetchAPI *m_fetch = nullptr;

    QString m_id;
    QImage m_image;
    QSize m_requestedSize;
};

class BASEFRONT_LIBRARYSHARED_EXPORT CorrentHostImageProvider: public QQuickAsyncImageProvider
{
public:
    CorrentHostImageProvider();
    ~CorrentHostImageProvider() override;

    QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize) override;

};
}
#endif // CORRENTHOSTIMAGEPROVIDER_H
