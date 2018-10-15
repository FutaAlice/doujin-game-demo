#include <QString>
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
}

Setting::~Setting()
{
    delete ui_;
}
