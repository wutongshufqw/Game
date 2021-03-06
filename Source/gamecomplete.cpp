//
// Created by y on 2022/6/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameComplete.h" resolved

#include "gamecomplete.h"
#include "Forms/ui_GameComplete.h"
#include "gameplay.h"
#include "mainwindow.h"
#include <QMouseEvent>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
GameComplete::GameComplete(bool nextLevel, bool flag, const QString &str, QWidget *parent) :
        QDialog(parent), ui(new Ui::GameComplete) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    QPainterPath path;
    QRectF rect = QRectF(0, 0, 654, 258);  //两点确定矩形范围，一般为控件大小，这样可以切割四个圆角，也可以调整大小，调整圆角个数
    path.addRoundRect(rect, 12, 30);   //后面两个参数的范围0-99，值越大越园
    QPolygon polygon = path.toFillPolygon().toPolygon();//获得这个路径上的所有的点
    QRegion region(polygon);//根据这些点构造这个区域
    setMask(region);

    if (flag)
        ui->message->setText("You Win!\n用时：" + str);
    else
        ui->message->setText("You Lose!");

    ui->next->setEnabled(nextLevel && flag);

    QFile GPQss(":/qss/qss/gamecomplete.qss");
    if (GPQss.open(QFile::ReadOnly))
        this->setStyleSheet(GPQss.readAll());

    connect(ui->back, &QPushButton::clicked, this, &QDialog::close);
    connect(ui->back, &QPushButton::clicked, dynamic_cast<GamePlay *>(parent), &GamePlay::back);
    connect(ui->back, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()->parentWidget()),
            &MainWindow::press);

    connect(ui->replay, &QPushButton::clicked, this, &QDialog::close);
    connect(ui->replay, &QPushButton::clicked, dynamic_cast<GamePlay *>(parent), &GamePlay::restart);
    connect(ui->replay, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()->parentWidget()),
            &MainWindow::press);

    connect(ui->next, &QPushButton::clicked, this, &QDialog::close);
    connect(ui->next, &QPushButton::clicked, dynamic_cast<GamePlay *>(parent), &GamePlay::nextLevel);
    connect(ui->next, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()->parentWidget()),
            &MainWindow::press);
}

GameComplete::~GameComplete() {
    delete ui;
}

void GameComplete::mousePressEvent(QMouseEvent *event) {
    this->windowPos = this->pos();
    this->mousePos = event->globalPos();
    this->dPos = mousePos - windowPos;
}

void GameComplete::mouseMoveEvent(QMouseEvent *event) {
    this->move(event->globalPos() - this->dPos);
}

#pragma clang diagnostic pop