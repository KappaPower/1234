#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Windows"));
    qDebug()<<QStyleFactory::keys();
    MainWindow w;
    w.show();

    return a.exec();
}
