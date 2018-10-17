#include <QResizeEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QPixmap>
#include <cli-args/cli.h>
#include "stglayer.h"
#include "ui_stglayer.h"

STGLayer::STGLayer(QWidget *parent)
    : QWidget(parent)
    , ui_(new Ui::STGLayerClass)
{
    ui_->setupUi(this);
    ui_->bg->move(0, 0);
}

STGLayer::~STGLayer()
{
    delete ui_;
}

void STGLayer::resizeEvent(QResizeEvent *e)
{
    ui_->bg->resize(e->size());
    ui_->bg->setPixmap(QPixmap(cli::resource_dir + "/battleback/playground.png").scaled(e->size()));
}

void STGLayer::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "STG layer press.";

    if (e->button() == Qt::RightButton)
        emit sigCallSettingLayer();
}