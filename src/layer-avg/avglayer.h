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
    AVGLayer(QWidget *parent = nullptr);
    ~AVGLayer();

protected:
    virtual void resizeEvent(QResizeEvent *);

private:
    Ui::AVGLayerClass *ui_;
};