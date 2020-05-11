//#
//# Copyright (C) 2020-2020 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "reader.h"

#include <QFile>
namespace BaseFront {

Reader::Reader() {

}

QString BaseFront::Reader::read(const QString &page) {
    QFile source(page);
    QString result;
    if (source.open(QIODevice::ReadOnly)) {

        result = source.readAll();
        source.close();
    }

    return result;
}

Reader *Reader::instance() {
    static auto instance = new Reader();
    return instance;
}
}
