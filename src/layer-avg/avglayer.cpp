#include <vector>
#include <QDebug>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QPixmap>
#include <cli-args/cli.h>
#include "avglayer.h"
#include "ui_avglayer.h"

std::vector<const char *> info {
    "测试～测试～ 在对话框上单击显示下一条文本",
    "在对话框上右击呼出设置菜单，再次右击可退出设置界面",
    "点击设置菜单的“Title”按钮返回标题画面",
    "通过标题界面的 DEBUG 按钮测试 STG 层",
    "TODO: 脚本嵌入(lua/python)",
    "TODO: 音效播放接口类",
    "TODO: 物理引擎",
    "TODO: 鼠标样式",
    "TODO: 动画 & 特效",
    "TODO: 还有很多没想起来的",
};

AVGLayer::AVGLayer(QWidget *parent)
    : QWidget(parent)
    , ui_(new Ui::AVGLayerClass)
{
    ui_->setupUi(this);
    // window()->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui_->text->setText(info[0]);
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

    ui_->name->setText("GOD");
    ui_->name->move(ui_->dialog->pos().x() + 60, ui_->dialog->pos().y() + 40);

    ui_->text->resize(width(), 20);
    ui_->text->move(ui_->dialog->pos().x() + 80, ui_->dialog->pos().y() + 80);
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
        ui_->text->setText(info[i++]);
    }
}