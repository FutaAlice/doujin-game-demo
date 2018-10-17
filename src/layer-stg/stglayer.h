#pragma once

#include <QWidget>
#include <QTimer>
#include "stglayer_global.h"

namespace Ui {
    class STGLayerClass;
}

class STGLAYERSHARED_EXPORT STGLayer
    : public QWidget
{
    Q_OBJECT

public:
    explicit STGLayer(QWidget *parent = nullptr);
    ~STGLayer();

signals:
    void sigCallSettingLayer();

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);

private slots:
    virtual void onTimerTimeout();

private:
    Ui::STGLayerClass *ui_;
    QTimer timer_ { this };
    bool kb_status_[0xff];
};
