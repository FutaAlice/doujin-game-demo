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

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(800, 600);
    setPresentWidget(Layer::Title);

    // connections with title layer
    connect(&title, SIGNAL(onSettingBtnClicked()), this, SLOT(showSettingLayer()));

    // connections with setting layer
    connect(&setting, SIGNAL(sigHide()), this, SLOT(hideSettingLayer()));
    connect(&setting, SIGNAL(sigScreenSize(QSize)), this, SLOT(setWindowSize(QSize)));
    connect(&setting, SIGNAL(sigFullScreen()), this, SLOT(setFullScreen()));

    avg.raise();
}

MainWidget::~MainWidget()
{
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

void MainWidget::setPresentWidget(Layer layer)
{
    static std::mutex m;

    if (!m.try_lock())
        return;

    std::thread t;
    switch (layer) {
        case Layer::Title:
            setPresentWidget(Layer::Null);
            title.raise();
            title.showBtn();
            title.show();
            break;
        default:
            break;
    }
    if (t.joinable()) {
        t.detach();
    } else {
        m.unlock();
    }
}

void MainWidget::setSettingLayerVisible(bool visible)
{
    static std::mutex m;
    if (!m.try_lock())
        return;

    setting.show();
    setting.raise();
    auto t = std::thread([&, visible] {
        std::lock_guard<std::mutex> lock (m, std::adopt_lock);
        auto easeFunc = [](double x) {
            return x == 0 ? 0 : x == 1 ? 1 :
                -pow(2,10 * x - 10) * sin((x * 10 - 10.75) * ((2 * 3.14)/ 3));
        };
        for (int i = 0; i <= 300; ++i) {
            double x = 1.0f * i / 300;
            double w = easeFunc(1.0 - x) * width();
            setting.move((int)w - (visible ? 0 : width()), 0);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        if (!visible)
            setting.hide();
    });
    t.detach();
}

void MainWidget::showSettingLayer()
{
    title.hideBtn();
    setSettingLayerVisible(true);
}

void MainWidget::hideSettingLayer()
{
    title.showBtn();
    setSettingLayerVisible(false);
}

void MainWidget::resizeEvent(QResizeEvent *e)
{
    title.resize(e->size());
    setting.resize(e->size());
    avg.resize(e->size());
    stg.resize(e->size());
}