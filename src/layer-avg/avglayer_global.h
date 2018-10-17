#pragma once
#include <QtCore/qglobal.h>

#if defined(AVGLAYER_LIBRARY)
#  define AVGLAYERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define AVGLAYERSHARED_EXPORT Q_DECL_IMPORT
#endif
