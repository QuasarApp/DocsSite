#ifndef PATRONUM_GLOBAL_H
#define PATRONUM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BASE_FRONT_LIBRARY)
#  define BASEFRONT_LIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BASEFRONT_LIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif


#endif // PATRONUM_GLOBAL_H