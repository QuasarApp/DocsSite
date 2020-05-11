//#
//# Copyright (C) 2020-2020 QuasarApp.
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef READER_H
#define READER_H

#include "BaseFront_global.h"
#include <QObject>


namespace BaseFront {
/**
 * @brief The Reader class - this class provide a simle methods for read html source code from resources of filesystem.
 */
class BASEFRONT_LIBRARYSHARED_EXPORT Reader
{
    Q_GADGET
public:
    /**
     * @brief read - read a source file
     * @param page - path to page
     * @return text of page. @note If the page not readed this method return a empty string.
     */
    Q_INVOKABLE QString read(const QString &page);

    static Reader* instance();

private:

    Reader();

};
}

Q_DECLARE_METATYPE(BaseFront::Reader*);

#endif // READER_H
