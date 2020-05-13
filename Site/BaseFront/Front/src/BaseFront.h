//#
//# Copyright (C) 2020-2020 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef BaseFront_H
#define BaseFront_H

#include "BaseFront_global.h"

class QQmlApplicationEngine;

/**
 * @brief The BaseFront namespace - Сontains base FrontEnd solutions for create sites and applications.
 *  After init in qml available next instances:
 *  - pageReader - see more information in Reader.
 */
namespace BaseFront {
    /**
     * @brief init - init all instances of this library.
     * @param engine - qml engine
     * @return - true if the function finished is seccussful.
     */
    bool init(QQmlApplicationEngine *engine);
};
#endif // BaseFront_H
