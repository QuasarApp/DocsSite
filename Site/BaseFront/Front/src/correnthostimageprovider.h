#ifndef CORRENTHOSTIMAGEPROVIDER_H
#define CORRENTHOSTIMAGEPROVIDER_H

#include <QQuickAsyncImageProvider>
#include <QRunnable>
#include "BaseFront_global.h"


namespace BaseFront {

class BASEFRONT_LIBRARYSHARED_EXPORT AsyncImageResponse : public QQuickImageResponse, public QRunnable
{
public:
    AsyncImageResponse(const QString &id, const QSize &requestedSize);

    QQuickTextureFactory *textureFactory() const;

    void run();

    QString m_id;
    QSize m_requestedSize;
    QImage m_image;
};

class BASEFRONT_LIBRARYSHARED_EXPORT CorrentHostImageProvider: public QQuickAsyncImageProvider
{
public:
    CorrentHostImageProvider();
    ~CorrentHostImageProvider();

    QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize) override;

};
}
#endif // CORRENTHOSTIMAGEPROVIDER_H
