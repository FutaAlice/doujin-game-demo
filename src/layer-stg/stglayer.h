#pragma once

#include <QWidget>

namespace Ui {
    class STGLayerClass;
}

class STGLayer
    : public QWidget
{
    Q_OBJECT

public:
    explicit STGLayer(QWidget *parent = nullptr);
    ~STGLayer();
private:
    Ui::STGLayerClass *ui_;
};
