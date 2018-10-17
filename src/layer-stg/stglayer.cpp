#include <QKeyEvent>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QDebug>
#include <QPixmap>
#include <cli-args/cli.h>
#include "stglayer.h"
#include "ui_stglayer.h"

QLabel *temp;

STGLayer::STGLayer(QWidget *parent)
    : QWidget(parent)
    , ui_(new Ui::STGLayerClass)
{
    ui_->setupUi(this);
    ui_->bg->move(0, 0);

    memset(kb_status_, false, sizeof(kb_status_) * sizeof(bool));

    timer_.start(5);
    connect(&timer_, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));

    temp = new QLabel(this);
    temp->setPixmap(cli::resource_dir + "/aeroplane/ufo.png");
    temp->move(500, 500);
    temp->resize(40, 40);
    temp->raise();
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

void STGLayer::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_W:
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        kb_status_[e->key()] = true;
        break;
    }
}

void STGLayer::keyReleaseEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_W:
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        kb_status_[e->key()] = false;
        break;
    }
}

void STGLayer::onTimerTimeout()
{
    auto p = temp->pos();
    const int speed = 1;
    if (kb_status_[Qt::Key_W]) {
        p.setY(p.y() - speed);
    } else if (kb_status_[Qt::Key_S]) {
        p.setY(p.y() + speed);
    }
    if (kb_status_[Qt::Key_A])
        p.setX(p.x() - speed);
    else if (kb_status_[Qt::Key_D])
        p.setX(p.x() + speed);
    
    temp->move(p);
}
