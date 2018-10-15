#pragma once
#include <QWidget>
#include "setting_global.h"

namespace Ui {
class Setting;
}

class SETTINGSHARED_EXPORT Setting :
    public QWidget
{
    Q_OBJECT
public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();
private:
    Ui::Setting *ui_;
};
