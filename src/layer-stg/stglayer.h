#pragma once

#include <QWidget>
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

private:
    Ui::STGLayerClass *ui_;
};
