#include <QApplication>
#include <QPushButton>
#include <QFontDatabase>
#include <QFile>
#include <QDebug>
#include "mainwindow.h"
#include "Level.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    int localFont = QFontDatabase::addApplicationFont(":/qss/fonts/No.93-ShangShouMengDongTi-2.ttf");
    QFontDatabase::applicationFontFamilies(localFont);
    /*qDebug()<<localFont;
    QFontDatabase qfd;
    QStringList qsl = qfd.families();
    for(int i = 0; i < 2; i++) {
        qDebug(qsl.at(i).toStdString().c_str());
    }*/
    MainWindow window(&app);
    window.show();
    return QApplication::exec();
}
