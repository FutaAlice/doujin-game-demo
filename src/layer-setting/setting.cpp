#include <QString>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QStyleOption>
#include <cli-args/cli.h>
#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent/* = nullptr*/) :
    QWidget(parent),
    ui_(new Ui::Setting)
{
    auto qss = QString("background-image: url(%1)")
        .arg(cli::resource_dir + "/background/setting_bg.png");
    setStyleSheet(qss);
    new QPushButton(this);
}

Setting::~Setting()
{
    delete ui_;
}

void Setting::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}