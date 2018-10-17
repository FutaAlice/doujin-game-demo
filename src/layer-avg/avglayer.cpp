#include "avglayer.h"
#include "ui_avglayer.h"

AVGLayer::AVGLayer(QWidget *parent)
    : QWidget(parent)
    , ui_(new Ui::AVGLayerClass)
{
    ui_->setupUi(this);
}

AVGLayer::~AVGLayer()
{
    delete ui_;
}

void AVGLayer::resizeEvent(QResizeEvent *e)
{

}