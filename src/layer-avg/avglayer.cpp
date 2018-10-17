#include <QDebug>
#include <QResizeEvent>
#include <QPixmap>
#include <cli-args/cli.h>
#include "avglayer.h"
#include "ui_avglayer.h"

AVGLayer::AVGLayer(QWidget *parent)
    : QWidget(parent)
    , ui_(new Ui::AVGLayerClass)
{
    ui_->setupUi(this);
    window()->setAttribute(Qt::WA_TransparentForMouseEvents);
}

AVGLayer::~AVGLayer()
{
    delete ui_;
}

void AVGLayer::resizeEvent(QResizeEvent *e)
{
    QSize s(
        e->size().width(),
        e->size().height() * 2 / 7
    );
    ui_->dialog->setPixmap(QPixmap(cli::resource_dir + "/system/avg_dialog.png").scaled(s));
    ui_->dialog->resize(s);
    ui_->dialog->move(0, e->size().height() - ui_->dialog->size().height());
}

void AVGLayer::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "AVG layer press.";
    QWidget::mousePressEvent(e);
}