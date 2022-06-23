//
// Created by y on 2022/6/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_MainWindow.h"
#include "gamestart.h"
#include <QProcess>

MainWindow::MainWindow(QApplication *app, QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow), app(app) {
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

    player = new QMediaPlayer(this);
    player->setMedia(QUrl(":/media/music/background.wav"));
    player->setVolume(80);
    player->play();

    game_start();

    connect(ui->exitGame, &QAction::triggered, this, &QMainWindow::close);
    connect(ui->restart, &QAction::triggered, this, &MainWindow::restart);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::game_start() {
    gameSelect->hide();
    gameStart->show();
}

void MainWindow::game_select() {
    gameStart->hide();
    if (gamePlay != nullptr)
        gamePlay->hide();
    gameSelect->show();
}

void MainWindow::game_play(QWidget *widget) {
    gamePlay = widget;
    gameSelect->hide();
    gamePlay->show();
}

void MainWindow::restart() {
    app->quit();
    QProcess::startDetached(app->applicationFilePath(), QStringList());
}
