/**
 * @file setting.cpp
 * @author FutaAlice (1611271600@qq.com)
 * @brief 设置菜单窗体
 * @version 0.1
 * @date 2018-10-16
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <QString>
#include <QPixmap>
#include <QResizeEvent>
#include <QMouseEvent>
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

    // back to title layer
    connect(ui_->btn_title, SIGNAL(clicked()), this, SIGNAL(sigBackToTitle()));

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
    ui_->bg->setPixmap(QPixmap(cli::resource_dir + "/system/setting_bg.png").scaled(size()));
    ui_->bg->resize(e->size());
    ui_->groupBox->move(
        (e->size().width() - ui_->groupBox->size().width()) / 2,
        (e->size().height() - ui_->groupBox->size().height()) / 2
    );
    ui_->btn_back->move(ui_->groupBox->geometry().bottomLeft());
    ui_->btn_title->move(ui_->btn_back->geometry().bottomLeft());
    ui_->btn_save->move(ui_->btn_title->geometry().bottomLeft());
    ui_->btn_load->move(ui_->btn_save->geometry().bottomLeft());
}

void Setting::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton)
        emit sigHide();
}