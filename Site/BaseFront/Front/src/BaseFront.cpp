//#
//# Copyright (C) 2020-2020 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "BaseFront.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

bool BaseFront::init(QQmlApplicationEngine *engine) {
    if (!engine)
        return false;


    auto root = engine->rootContext();
    if (!root)
        return false;
    engine->addImportPath(":/");

    return true;
}
