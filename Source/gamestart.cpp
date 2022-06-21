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
    QFile GSQss(":/qss/gamestart.qss");
    if (GSQss.open(QFile::ReadOnly))
        this->setStyleSheet(GSQss.readAll());
    connect(ui->start, &QPushButton::clicked, dynamic_cast<MainWindow*>(parent), &MainWindow::game_select);
    connect(ui->exit, &QPushButton::clicked, dynamic_cast<MainWindow*>(parent), &MainWindow::close);
}

GameStart::~GameStart() {
    delete ui;
}
