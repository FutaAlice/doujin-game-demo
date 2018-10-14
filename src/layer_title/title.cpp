#include <QVBoxLayout>
#include <QResizeEvent>
#include "giflabel.hpp"
#include "title.h"
#include "ui_title.h"

Title::Title(QWidget *parent/* = nullptr*/) :
    QWidget(parent),
    ui_(new Ui::Title)
{
    ui_->setupUi(this);
    
    title_gif_ = new GIFLabel(this, "/home/futa/Work/doujin-game-demo/resource/background/title_background.gif");
}

Title::~Title()
{
    delete ui_;
    delete title_gif_;
}

void Title::resizeEvent(QResizeEvent *e)
{
    title_gif_->resize(e->size());
}
