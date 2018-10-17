#include "stglayer.h"
#include "ui_stglayer.h"

STGLayer::STGLayer(QWidget *parent)
    : QWidget(parent)
    , ui_(new Ui::STGLayerClass)
{
    ui_->setupUi(this);
}

STGLayer::~STGLayer()
{
    delete ui_;
}