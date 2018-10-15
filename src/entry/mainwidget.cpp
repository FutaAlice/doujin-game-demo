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
#include <future>
#include <QDebug>
#include <QResizeEvent>
#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(800, 600);
    setPresentWidget(Layer::Title);

    // connections with title layer
    connect(&title, SIGNAL(onSettingBtnClicked()), this, SLOT(presentSettingLayer()));
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

void MainWidget::setPresentWidget(Layer layer)
{
    static std::future<void> layerFade;
    if (layerFade.valid())
        return;

    switch (layer) {
        case Layer::Title:
            setPresentWidget(Layer::Null);
            title.raise();
            title.show();
            break;
        case Layer::Setting:
            setting.move(width(), 0);
            setting.raise();
            setting.show();
            layerFade = std::async(std::launch::async, [this] {
                auto easeFunc = [](double x) {
                    return x == 0 ? 0 : x == 1 ? 1 :
                        -pow(2,10 * x - 10) * sin((x * 10 - 10.75) * ((2 * 3.14)/ 3));
                };
                for (int i = 0; i <= 1000; ++i) {
                    double x = 1.0f * i / 1000;
                    double w = easeFunc(1.0 - x) * width();
                    setting.move((int)w, 0);
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                }
                // for (int x = width(); x != 0;x = setting.pos().x()) {
                //     setting.move(std::max(x - 1, 0), 0);
                //     std::this_thread::sleep_for(std::chrono::milliseconds(1));
                // }
            });
            break;
        case Layer::Null:
        default:
            break;
    }
}

void MainWidget::presentSettingLayer()
{
    setPresentWidget(Layer::Setting);
}

void MainWidget::resizeEvent(QResizeEvent *e)
{
    title.resize(e->size());
    setting.resize(e->size());
}