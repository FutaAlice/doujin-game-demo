#pragma once
#include <QtCore/qglobal.h>
#include <QString>

#if defined(CLI_LIBRARY)
#  define CLISHARED_EXPORT Q_DECL_EXPORT
#else
#  define CLISHARED_EXPORT Q_DECL_IMPORT
#endif

namespace cli {

extern CLISHARED_EXPORT QString resource_dir;

CLISHARED_EXPORT bool init(int argc, char **argv);

} // namespace cli
