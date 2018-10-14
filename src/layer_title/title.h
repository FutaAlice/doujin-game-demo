#pragma once
#include <QLabel>
#include <QWidget>
#include "title_global.h"

namespace Ui {
class Title;
}

class GIFContainer;

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
    QMovie *title_bg_;
    QLabel *label_bg_;
    GIFContainer *title_gif_;
};
