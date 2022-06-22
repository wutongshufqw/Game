//
// Created by y on 2022/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "gameplay.h"
#include "gamestart.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("一笔画小游戏");
    setWindowIcon(QIcon(":/mainwindow/images/icon.jpg"));
    setFixedSize(QSize(1280, 820));
    centre = new QWidget(this);
    gameStart = new GameStart(centre);
    gameSelect = new GameSelect(centre);
    gameStart->hide();
    gameSelect->hide();
    setCentralWidget(centre);
    game_start();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::game_start(){
    gameSelect->hide();
    gameStart->show();
//    setCentralWidget(gameStart);
}

void MainWindow::game_select() {
    gameStart->hide();
    if(gamePlay!= nullptr)
        gamePlay->hide();
    gameSelect->show();
//    setCentralWidget(gameSelect);
}

void MainWindow::game_play(QWidget* widget) {
    gamePlay = widget;
    gameSelect->hide();
    gamePlay->show();
//    setCentralWidget(gamePlay);
}