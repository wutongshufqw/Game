//
// Created by y on 2022/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "gameplay.h"
#include "gamestart.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("一笔画小游戏");
    setWindowIcon(QIcon(":/mainwindow/icon.jpg"));
    setFixedSize(QSize(1280, 820));
    gameStart = new GameStart(this);
    setCentralWidget(gameStart);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::game_select() {
    gameSelect = new GameSelect(gameStart);
    gameStart->hide();
    setCentralWidget(gameSelect);
}


