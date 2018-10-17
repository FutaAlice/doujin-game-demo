#include <vector>
#include <QDebug>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QPixmap>
#include <cli-args/cli.h>
#include "avglayer.h"
#include "ui_avglayer.h"

std::vector<QString> info;
std::vector<QLabel *> v(10);

AVGLayer::AVGLayer(QWidget *parent)
    : QWidget(parent)
    , ui_(new Ui::AVGLayerClass)
{
    ui_->setupUi(this);

    // initialize character group
    for (auto & x : v) {
        x = new QLabel(this);
        x->lower();
    }

    // window()->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui_->name->setText("GOD");

    ui_->bg->lower();

    QFile file(cli::resource_dir + "/script/drama.lua");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        info.push_back(line);
        line = in.readLine();
    }

    if (info.size() >= 1)
        ui_->text->setText(info[0]);
}

AVGLayer::~AVGLayer()
{
    delete ui_;
}

void AVGLayer::resizeEvent(QResizeEvent *e)
{
    for (auto x : v) {
        x->resize(width() / 6, height() * 4 / 5);
    }

    QSize s(
        e->size().width(),
        e->size().height() * 2 / 7
    );
    ui_->dialog->setPixmap(QPixmap(cli::resource_dir + "/system/avg_dialog.png").scaled(s));
    ui_->dialog->resize(s);
    ui_->dialog->move(0, e->size().height() - ui_->dialog->size().height());

    ui_->name->move(ui_->dialog->pos().x() + 60, ui_->dialog->pos().y() + 40);

    ui_->text->resize(width(), 20);
    ui_->text->move(ui_->dialog->pos().x() + 80, ui_->dialog->pos().y() + 80);

    ui_->bg->move(0, 0);
    ui_->bg->resize(e->size());
    ui_->bg->setPixmap(QPixmap(cli::resource_dir + "/background/earth.png").scaled(e->size()));
}

void AVGLayer::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "AVG layer press.";
    auto area = ui_->dialog->geometry();
    if (!area.contains(e->pos())) {
        QWidget::mousePressEvent(e);
        return;
    }

    if (e->button() == Qt::RightButton)
        emit sigCallSettingLayer();
    else {
        static int i = 1;
        if (i >= info.size()) {
            i = 0;
        }
        if (info.empty())
            return;
        ui_->text->setText(info[i++]);

        v[0]->setPixmap(QPixmap(cli::resource_dir + "/character/god.png").scaled(v[0]->size()));
        v[0]->move(
            width() / 2,
            height() - v[0]->height()
        );
    }
}