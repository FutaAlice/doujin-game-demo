/**
 * @file title.cpp
 * @author FutaAlice (1611271600@qq.com)
 * @brief 标题画面
 * @version 0.1
 * @date 2018-10-16
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <QPushButton>
#include <QVBoxLayout>
#include <QResizeEvent>
#include <QDebug>
#include <QPixmap>
#include <QImage>
#include <cli-args/cli.h>
#include "giflabel.hpp"
#include "title.h"
#include "ui_title.h"

Title::Title(QWidget *parent/* = nullptr*/) :
    QWidget(parent),
    ui_(new Ui::Title)
{
    ui_->setupUi(this);
    
    title_gif_ = new GIFLabel(this);
    title_gif_->load(cli::resource_dir + "/background/title_background.gif");

    auto getTitleBtn = [this](QString imgsrc, int CutSec) {
        QPushButton *btn = new QPushButton(this);
        imgsrc = cli::resource_dir + imgsrc;
        int img_w = QPixmap(imgsrc).width();
        int img_h = QPixmap(imgsrc).height();
        int PicWidth = img_w / CutSec;
        btn->setFixedSize(PicWidth, img_h);
        btn->setStyleSheet(
            QString()
                .append("QPushButton{border-image: url(%1) 0 0 0 %2 repeat repeat;border-width: 0px; border-radius: 0px;}")
                .append("QPushButton::hover{border-image: url(%1) 0 0 0 %3  repeat repeat;}")
                .append("QPushButton::pressed{border-image: url(%1) 0 0 0 %4 repeat repeat;}")
                .append("QPushButton::checked{border-image: url(%1) 0 0 0 %4 repeat repeat;}")
                .append("QPushButton::disabled{border-image: url(%1) 0 0 0 %5 repeat repeat;}")
                .arg(imgsrc).arg(0).arg(PicWidth).arg(PicWidth * 2).arg(PicWidth * 3)
        );
        return btn;
    };

    btn_ctn_ = new QWidget(this);
    auto *btn_layout = new QVBoxLayout(btn_ctn_);
    btn_ctn_->setLayout(btn_layout);
    btn_ctn_->resize(100, 240);

    btn_layout->addWidget(getTitleBtn("/button/btn_start.png", 4));
    btn_layout->addWidget(getTitleBtn("/button/btn_continue.png", 4));
    auto btn = getTitleBtn("/button/btn_setting.png", 4);
    btn_layout->addWidget(btn);
    btn_layout->addWidget(getTitleBtn("/button/btn_about.png", 4));
    btn_layout->addWidget(getTitleBtn("/button/btn_debug.png", 4));

    connect(btn, SIGNAL(clicked()), this, SIGNAL(onSettingBtnClicked()));
}

Title::~Title()
{
    delete ui_;
    delete title_gif_;
}

void Title::showBtn()
{
    btn_ctn_->show();
}

void Title::hideBtn()
{
    btn_ctn_->hide();
}

void Title::resizeEvent(QResizeEvent *e)
{
    title_gif_->resize(e->size());
    btn_ctn_->move(
        (e->size().width() - btn_ctn_->size().width()) / 2,
        (e->size().height() - btn_ctn_->size().height()) / 2
    );
}

void Title::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "Title mouse press";
}