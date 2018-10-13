#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtCore/QDebug>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget widget;
    widget.show();
    qDebug() << "doujin game demo.";
    return app.exec();
}
