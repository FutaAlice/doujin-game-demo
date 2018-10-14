#pragma once
#include <QLabel>
#include <QMovie>
#include <QResizeEvent>

class GIFLabel :
    public QLabel
{
public:
    GIFLabel(QWidget *parentWidget) :
        QLabel(parentWidget)
    {
    }
    ~GIFLabel()
    {
        delete movie_;
    }
    void load(QString filename)
    {
        delete movie_;
        movie_ = new QMovie(filename);
        movie_->start();
        setMovie(movie_);
    }
protected:
    virtual void resizeEvent(QResizeEvent *e)
    {
        if (movie_)
            movie_->setScaledSize(e->size());
        QLabel::resizeEvent(e);
    }
private:
    QMovie *movie_ { nullptr };
};