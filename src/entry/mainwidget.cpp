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
#include <QMovie>
#include <QLabel>
#include <QImage>
#include <QDebug>
#include <QPixmap>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    qDebug() << "fuck";
    QMovie *movie = new QMovie("/home/futa/Work/doujin-game-demo/resource/background/title_background.gif");
    QLabel *label = new QLabel(this);
    label->setMovie(movie);
    // label->setText("fuck");
    movie->start();
    label->show();
    setPresentWidget(label);
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
    delete main_layout_;
    main_layout_ = nullptr;
    if (pSubWidget) {
        main_layout_ = new QHBoxLayout;
        main_layout_->addWidget(pSubWidget);
        setLayout(main_layout_);
    }
}
