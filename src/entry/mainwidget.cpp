/**
 * @file mainwidget.cpp
 * @author FutaAlice (1611271600@qq.com)
 * @brief 主窗体
 * @version 0.1
 * @date 2018-10-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <QDebug>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(800, 600);
    setPresentWidget(&title);
}

MainWidget::~MainWidget()
{
}

void MainWidget::setWindowSize(const QSize &size)
{
    setFixedSize(size);
}

void MainWidget::setWindowSize(int w, int h)
{
    setFixedSize(w, h);
}

void MainWidget::setPresentWidget(QWidget *pSubWidget)
{
    delete layout();    
    if (pSubWidget) {
        auto main_layout = new QHBoxLayout;
        main_layout->setMargin(0);
        main_layout->addWidget(pSubWidget);
        setLayout(main_layout);
    }
}
