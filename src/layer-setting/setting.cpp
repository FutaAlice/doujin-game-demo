#include <QString>
#include <QPixmap>
#include <QResizeEvent>
#include <cli-args/cli.h>
#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent/* = nullptr*/) :
    QWidget(parent),
    ui_(new Ui::Setting)
{
    ui_->setupUi(this);
}

Setting::~Setting()
{
    delete ui_;
}

void Setting::paintEvent(QPaintEvent *e)
{
}

void Setting::resizeEvent(QResizeEvent *e)
{
    ui_->bg->setPixmap(QPixmap(cli::resource_dir + "/background/setting_bg.png").scaled(size()));
    ui_->bg->resize(e->size());
}
