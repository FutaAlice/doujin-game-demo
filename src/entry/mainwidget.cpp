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
#include <cmath>
#include <chrono>
#include <thread>
#include <mutex>
#include <future>
#include <QDebug>
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
    connect(&title_, SIGNAL(onSettingBtnClicked()), this, SLOT(showSettingLayer()));

    // connections with setting layer
    connect(&setting_, SIGNAL(sigHide()), this, SLOT(hideSettingLayer()));
    connect(&setting_, SIGNAL(sigScreenSize(QSize)), this, SLOT(setWindowSize(QSize)));
    connect(&setting_, SIGNAL(sigFullScreen()), this, SLOT(setFullScreen()));
    connect(&setting_, SIGNAL(sigBackToTitle()), this, SLOT(init()));
    
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
    static std::mutex m;
    if (!m.try_lock())
        return;

    setting_.show();
    setting_.raise();
    auto t = std::thread([&, visible] {
        std::lock_guard<std::mutex> lock (m, std::adopt_lock);
        auto easeFunc = [](double x) {
            return x == 0 ? 0 : x == 1 ? 1 :
                -pow(2,10 * x - 10) * sin((x * 10 - 10.75) * ((2 * 3.14)/ 3));
        };
        for (int i = 0; i <= 300; ++i) {
            double x = 1.0f * i / 300;
            double w = easeFunc(1.0 - x) * width();
            setting_.move((int)w - (visible ? 0 : width()), 0);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        if (!visible)
            setting_.hide();
    });
    t.detach();
}

void MainWidget::setAVGLayerVisible(bool visible)
{
    static std::mutex m;
    if (!m.try_lock())
        return;

    avg_.show();
    avg_.raise();
    auto t = std::thread([&, visible] {
        std::lock_guard<std::mutex> lock (m, std::adopt_lock);
        if (!visible)
            avg_.hide();
    });
    t.detach();
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