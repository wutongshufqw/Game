//
// Created by y on 2022/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "gameplay.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setFixedSize(QSize(1280,820));
    setWindowTitle("一笔画小游戏");
    setWindowIcon(QIcon(":/mainwindow/icon.jpg"));
    GamePlay *gamePlay = new GamePlay(this);
    setCentralWidget(gamePlay);
}

MainWindow::~MainWindow() {
    delete ui;
}
