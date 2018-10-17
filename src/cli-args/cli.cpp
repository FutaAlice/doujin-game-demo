#include <string>
#include <iostream>
#ifdef WIN32
#  include <filesystem>
#else
#  include <experimental/filesystem>
#endif // WIN32
#include <QDebug>
#include <args/args.hxx>
#include "cli.h"

namespace cli {

QString resource_dir;

bool init(int argc, char **argv)
{   
    namespace fs = std::experimental::filesystem;
    auto current_path = fs::current_path();

    args::ArgumentParser parser("This is a doujin game demo.");
    args::HelpFlag help(parser, "help", "Display this help menu", { 'h', "help" });
    args::ValueFlag<std::string> str_resource_dir(
        parser, "resource-dir", "directory of resource folder",
        { 'r', "resource-dir" }, current_path.string()
    );
    try {
        parser.ParseCLI(argc, argv);
    } catch (args::Help) {
        std::cout << parser;
        getchar();
        return false;
    }

    cli::resource_dir = QString::fromStdString(args::get(str_resource_dir)) + "/resource";
    cli::resource_dir.replace("\\", "/");

    qDebug() << "resource in folder:" << cli::resource_dir << "will be load.";
    return true;
}

} // namespace cli
