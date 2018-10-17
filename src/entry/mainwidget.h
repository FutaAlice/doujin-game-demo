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
#include <set>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <layer-title/title.h>
#include <layer-setting/setting.h>
#include <layer-avg/avglayer.h>
#include <layer-stg/stglayer.h>

enum class Layer {
    Title,
    Setting,
    AVG,
    STG,
    Null,
};

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public:
    void setSettingLayerVisible(bool);
    void setAVGLayerVisible(bool);
    void setSTGLayerVisible(bool);

public slots:
    void init();
    void setWindowSize(const QSize &);
    void setWindowSize(int w, int h);
    void setFullScreen();
    void showSettingLayer();
    void hideSettingLayer();
    void showAVGLayer();
    void hideAVGLayer();
    void showSTGLayer();
    void hideSTGLayer();

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void mousePressEvent(QMouseEvent *);

private:
    Title title_ { this };
    Setting setting_ { this };
    AVGLayer avg_ { this };
    STGLayer stg_ { this };

    std::set<QWidget *> layers_;

    const int anime_duration_ { 300 };
};
