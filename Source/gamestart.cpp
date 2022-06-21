//
// Created by 24157 on 2022/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameStart.h" resolved

#include "gamestart.h"
#include "Forms/ui_GameStart.h"
#include "gameselect.h"
#include "mainwindow.h"


GameStart::GameStart(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameStart) {
    ui->setupUi(this);
    GameSelect *gameSelect = new GameSelect(this);
    connect(ui->exit, &QPushButton::clicked, parent, &QMainWindow::close);
    connect(ui->start, &QPushButton::clicked, parent, &MainWindow::game_select);
}

GameStart::~GameStart() {
    delete ui;
}
