#include <QApplication>
#include <QPushButton>
#include "Headers/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
