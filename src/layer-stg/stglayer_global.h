#pragma once
#include <QtCore/qglobal.h>

#if defined(STGLAYER_LIBRARY)
#  define STGLAYERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define STGLAYERSHARED_EXPORT Q_DECL_IMPORT
#endif
