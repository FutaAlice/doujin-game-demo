/**
 * @file main.cpp
 * @author FutaAlice (1611271600@qq.com)
 * @brief 程序入口点
 * @version 0.1
 * @date 2018-10-16
 * 
 * @copyright Copyright (c) 2018
 * 
 */
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
