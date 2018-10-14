#pragma once
#include <QLabel>
#include <QWidget>
#include "title_global.h"

namespace Ui {
class Title;
}

class GIFLabel;

class TITLESHARED_EXPORT Title :
    public QWidget
{
    Q_OBJECT
public:
    explicit Title(QWidget *parent = nullptr);
    ~Title();

protected:
    virtual void resizeEvent(QResizeEvent *);

private:
    Ui::Title *ui_;
    GIFLabel *title_gif_;
};