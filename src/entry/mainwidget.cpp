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
#include <QPropertyAnimation>
#include <QApplication>
#include <QDesktopWidget>
#include <QResizeEvent>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , layers_ { &title_, &setting_, &avg_, &stg_ }

{
    init();

    // connections with title layer
    connect(&title_, SIGNAL(sigCallSettingLayer()), this, SLOT(showSettingLayer()));
    connect(&title_, SIGNAL(sigCallAVGLayer()), this, SLOT(showAVGLayer()));

    // connections with setting layer
    connect(&setting_, SIGNAL(sigHide()), this, SLOT(hideSettingLayer()));
    connect(&setting_, SIGNAL(sigScreenSize(QSize)), this, SLOT(setWindowSize(QSize)));
    connect(&setting_, SIGNAL(sigFullScreen()), this, SLOT(setFullScreen()));
    connect(&setting_, SIGNAL(sigBackToTitle()), this, SLOT(init()));
    
    // connections with AVG layer
    connect(&avg_, SIGNAL(sigCallSettingLayer()), this, SLOT(showSettingLayer()));
}

MainWidget::~MainWidget()
{
}

void MainWidget::init()
{
    setWindowSize(1280, 720);
    for (auto x : layers_) {
        x->hide();
    }
    title_.show();
    title_.showBtn();
}

void MainWidget::setWindowSize(const QSize &size)
{
    showNormal();
    setFixedSize(size);
}

void MainWidget::setWindowSize(int w, int h)
{
    showNormal();
    setFixedSize(w, h);
}

void MainWidget::setFullScreen()
{
    setWindowSize(QApplication::desktop()->size());
    showFullScreen();
}

void MainWidget::setSettingLayerVisible(bool visible)
{
    setting_.show();
    setting_.raise();

    QPoint pos[2] = {
        { 0, 0 },
        { width(), 0 },
    };

    auto *anime = new QPropertyAnimation(&setting_, "pos");
    anime->setDuration(anime_duration_);
    anime->setStartValue(pos[visible]);
    anime->setEndValue(pos[!visible]);
    anime->setEasingCurve(QEasingCurve::OutElastic);
    anime->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWidget::setAVGLayerVisible(bool visible)
{
    avg_.show();
    avg_.raise();

    QPropertyAnimation *anime = new QPropertyAnimation(&avg_, "windowOpacity");
    anime->setDuration(anime_duration_);
    anime->setStartValue(visible);
    anime->setEndValue(!visible);
    anime->setEasingCurve(QEasingCurve::OutElastic);
    anime->start(QAbstractAnimation::DeleteWhenStopped);

}

void MainWidget::showSettingLayer()
{
    title_.hideBtn();
    setSettingLayerVisible(true);
}

void MainWidget::hideSettingLayer()
{
    title_.showBtn();
    setSettingLayerVisible(false);
}

void MainWidget::showAVGLayer()
{
    setAVGLayerVisible(true);
}

void MainWidget::hideAVGLayer()
{
    setAVGLayerVisible(false);
}

void MainWidget::resizeEvent(QResizeEvent *e)
{
    for (auto x : layers_)
        x->resize(e->size());
}

void MainWidget::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "MainWidget mouse press.";
}