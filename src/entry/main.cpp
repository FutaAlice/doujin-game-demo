#include <string>
#include <iostream>
#ifdef WIN32
#  include <filesystem>
#else
#  include <experimental/filesystem>
#endif // WIN32
#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <args/args.hxx>
#include "mainwidget.h"

QString resource_dir;

int main(int argc, char **argv)
{
    namespace fs = std::experimental::filesystem;
    auto current_path = fs::current_path();

    args::ArgumentParser parser("This is a doujin game demo.");
    args::HelpFlag help(parser, "help", "Display this help menu", { 'h', "help" });
    args::ValueFlag<std::string> str_resource_dir(
        parser, "resource-dir", "directory of resource folder",
        { 'r', "resource-dir" }, current_path.c_str()
    );
    try {
        parser.ParseCLI(argc, argv);
    } catch (args::Help) {
        std::cout << parser;
        getchar();
        return 0;
    }

    resource_dir = QString::fromStdString(args::get(str_resource_dir)) + "/resource";
    qDebug() << "resource in folder:" << resource_dir << "will be load.";

    QApplication app(argc, argv);
    MainWidget widget;
    widget.show();
    return app.exec();
}
