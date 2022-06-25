//
// Created by y on 2022/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameStart.h" resolved

#include <QFile>
#include "gamestart.h"
#include "Forms/ui_GameStart.h"
#include "mainwindow.h"


GameStart::GameStart(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameStart) {
    ui->setupUi(this);
    setFixedSize(QSize(1280, 800));

    QFile GSQss(":/qss/qss/gamestart.qss");
    if (GSQss.open(QFile::ReadOnly))
        this->setStyleSheet(GSQss.readAll());

    connect(ui->start, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),
            &MainWindow::game_select);
    connect(ui->start, &QPushButton::clicked, this, &GameStart::hide);
    connect(ui->start, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()), &MainWindow::press);

    connect(ui->exit, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()), &MainWindow::close);
    connect(ui->exit, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()), &MainWindow::press);
}

GameStart::~GameStart() {
    delete ui;
}
