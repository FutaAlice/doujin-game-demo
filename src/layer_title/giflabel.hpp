#pragma once
#include <QLabel>
#include <QMovie>
#include <QResizeEvent>

class GIFLabel :
    public QLabel
{
public:
    GIFLabel(QWidget *parentWidget, QString filename) :
        QLabel(parentWidget)
    {
        movie_->start();
        setMovie(movie_);
        show();
    }
    ~GIFLabel()
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