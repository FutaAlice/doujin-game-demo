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

    // hide setting layer
    connect(ui_->btn_back, SIGNAL(clicked()), this, SIGNAL(sigHide()));

    // change window size
    connect(ui_->radio_dp_720, SIGNAL(clicked()), this, SLOT(changeScreenSize()));
    connect(ui_->radio_dp_900, SIGNAL(clicked()), this, SLOT(changeScreenSize()));
    connect(ui_->radio_dp_1080, SIGNAL(clicked()), this, SLOT(changeScreenSize()));
    connect(ui_->radio_dp_fs, SIGNAL(clicked()), this, SLOT(changeScreenSize()));

}

Setting::~Setting()
{
    delete ui_;
}

void Setting::changeScreenSize()
{
    QSize s;
    bool fullscreen = false;
    if (ui_->radio_dp_720->isChecked())
        s = QSize(1280, 720);
    else if (ui_->radio_dp_900->isChecked())
        s = QSize(1600, 900);
    else if (ui_->radio_dp_1080->isChecked())
        s = QSize(1920, 1080);
    else
        fullscreen = true;

    if (fullscreen)
        emit sigFullScreen();
    else
        emit sigScreenSize(s);
}

void Setting::paintEvent(QPaintEvent *e)
{
}

void Setting::resizeEvent(QResizeEvent *e)
{
    ui_->bg->setPixmap(QPixmap(cli::resource_dir + "/background/setting_bg.png").scaled(size()));
    ui_->bg->resize(e->size());
}
