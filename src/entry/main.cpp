#include <string>
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <args/args.hxx>
#include "mainwidget.h"

QString resource_dir;

int main(int argc, char **argv)
{
    args::ArgumentParser parser("This is a doujin game demo.");
    args::HelpFlag help(parser, "help", "Display this help menu", { 'h', "help" });
    args::ValueFlag<std::string> str_resource_dir(
        parser, "resource-dir", "directory of resource folder",
        { 'r', "resource-dir" }, "/"
    );
    try {
        parser.ParseCLI(argc, argv);
    } catch (args::Help) {
        std::cout << parser;
        getchar();
        return 0;
    }

    resource_dir = QString::fromStdString(args::get(str_resource_dir));
    qDebug() << "resource in folder:" << resource_dir << "will be load.";

    QApplication app(argc, argv);
    MainWidget widget;
    widget.show();
    return app.exec();
}
