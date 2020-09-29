//
// Copyright (C) 2020-2020 QuasarApp.
// Distributed under the lgplv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef IMAGESERVICE_H
#define IMAGESERVICE_H
#include "BaseFront_global.h"

#include <QHash>
#include <QImage>

namespace BaseFront {
class FetchAPI;

class BASEFRONT_LIBRARYSHARED_EXPORT ImageService: public QObject
{
    Q_OBJECT
public:
    ImageService(QObject* parent = nullptr);
    ~ImageService();

    const QImage& getImage(const QString& img) const;
private slots:
    void handle
private:
    QHash<QString, QImage> _data;
    FetchAPI * _fetchAPI;
};
}
#endif // IMAGESERVICE_H
