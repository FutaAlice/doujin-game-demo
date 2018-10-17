/**
 * @file title.h
 * @author FutaAlice (1611271600@qq.com)
 * @brief 标题画面
 * @version 0.1
 * @date 2018-10-16
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include <QLabel>
#include <QWidget>
#include "title_global.h"

namespace Ui {
class Title;
}

class GIFLabel;

class TITLESHARED_EXPORT Title :
    public QWidget
{
    Q_OBJECT
public:
    explicit Title(QWidget *parent = nullptr);
    ~Title();

    void showBtn();
    void hideBtn();

signals:
    void sigCallSettingLayer();
    void sigCallAVGLayer();

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void mousePressEvent(QMouseEvent *);

private:
    Ui::Title *ui_;
    GIFLabel *title_gif_;
    QWidget *btn_ctn_;
};
