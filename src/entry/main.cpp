#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <cli-args/cli.h>
#include "mainwidget.h"

int main(int argc, char **argv)
{
    if (!cli::init(argc, argv))
        return 0;

    QApplication app(argc, argv);
    MainWidget widget;
    widget.show();
    return app.exec();
}
