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
private:
    Ui::STGLayerClass *ui_;
};
