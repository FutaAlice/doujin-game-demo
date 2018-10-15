/**
 * @file mainwidget.h
 * @author FutaAlice (1611271600@qq.com)
 * @brief 主窗体
 * @version 0.1
 * @date 2018-10-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <layer-title/title.h>
#include <layer-setting/setting.h>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

public:
    void setWindowSize(const QSize &);
    void setWindowSize(int w, int h);
    void setPresentWidget(QWidget *);

private:
    Title title { this };
    Setting setting { this };
};
