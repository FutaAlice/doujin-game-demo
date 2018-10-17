#pragma once

#include <QWidget>
#include "avglayer_global.h"

namespace Ui {
    class AVGLayerClass;
}

class AVGLAYERSHARED_EXPORT AVGLayer
    : public QWidget
{
    Q_OBJECT

public:
    explicit AVGLayer(QWidget *parent = nullptr);
    ~AVGLayer();

protected:
    virtual void resizeEvent(QResizeEvent *);
    virtual void mousePressEvent(QMouseEvent *e);

private:
    Ui::AVGLayerClass *ui_;
};
