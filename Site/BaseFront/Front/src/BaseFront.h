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
 * @brief The BaseFront namespace - contains base frontend solutions for create sites and applications
 */
namespace BaseFront {
    bool init(QQmlApplicationEngine *engine);
};
#endif // BaseFront_H
