#pragma once
#include <QtCore/qglobal.h>

#if defined(SETTING_LIBRARY)
#  define SETTINGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SETTINGSHARED_EXPORT Q_DECL_IMPORT
#endif
