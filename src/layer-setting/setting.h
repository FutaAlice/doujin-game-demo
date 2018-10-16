#pragma once
#include <QWidget>
#include <QLabel>
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
protected slots:
    void changeScreenSize();
signals:
    void sigHide();
    void sigScreenSize(QSize);
    void sigFullScreen();
protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);
private:
    Ui::Setting *ui_;
};
