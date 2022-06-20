#include <QApplication>
#include <QPushButton>
#include "Headers/mainwindow.h"
#include "Headers/gameselect.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GameSelect w;
    w.show();
    return QApplication::exec();
}
