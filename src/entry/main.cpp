#include <QApplication>
#include <QWidget>
#include <QDebug>
#include "mainwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MainWidget widget;
    widget.show();
    qDebug() << "doujin game demo.";
    return app.exec();
}
