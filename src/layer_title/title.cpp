#include <QLabel>
#include <QMovie>
#include <QVBoxLayout>
#include <QResizeEvent>
#include "title.h"
#include "ui_title.h"

class GIFContainer :
    public QLabel
{
public:
    GIFContainer(QWidget *parentWidget, QString filename) :
        QLabel(parentWidget)
    {
        movie_->start();
        setMovie(movie_);
        show();
    }
    ~GIFContainer()
    {
        delete movie_;
    }
protected:
    virtual void resizeEvent(QResizeEvent *e)
    {
        movie_->setScaledSize(e->size());
        QLabel::resizeEvent(e);
    }
private:
    QMovie *movie_;
};

Title::Title(QWidget *parent/* = nullptr*/) :
    QWidget(parent),
    ui_(new Ui::Title)
{
    ui_->setupUi(this);
    
    title_gif_ = new GIFContainer(this, "/home/futa/Work/doujin-game-demo/resource/background/title_background.gif");
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
