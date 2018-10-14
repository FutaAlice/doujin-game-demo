#pragma once
#include <QtCore/qglobal.h>

#if defined(TITLE_LIBRARY)
#  define TITLESHARED_EXPORT Q_DECL_EXPORT
#else
#  define TITLESHARED_EXPORT Q_DECL_IMPORT
#endif
