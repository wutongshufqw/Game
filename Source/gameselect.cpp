//
// Created by 26412 on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameSelect.h" resolved

#include <QFile>
#include "gameselect.h"
#include "Forms/ui_GameSelect.h"


GameSelect::GameSelect(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameSelect) {
    ui->setupUi(this);
    setFixedSize(QSize(1280, 800));

    QFile GSQss(":/qss/qss/gameselect.qss");
    if (GSQss.open(QFile::ReadOnly))
        this->setStyleSheet(GSQss.readAll());

    connect(ui->level_1, &QPushButton::clicked, this, [=]() { emit play_game(new GamePlay(1, parent)); });
    connect(ui->level_1, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()), &MainWindow::press);

    connect(ui->level_2, &QPushButton::clicked, this, [=]() { emit play_game(new GamePlay(2, parent)); });
    connect(ui->level_2, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()), &MainWindow::press);

    connect(ui->level_3, &QPushButton::clicked, this, [=]() { emit play_game(new GamePlay(3, parent)); });
    connect(ui->level_3, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()), &MainWindow::press);

    connect(ui->difficulty_1, &QPushButton::clicked, this, [=]() { emit play_game(new GamePlay(1, parent, true, 1)); });
    connect(ui->difficulty_1, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),
            &MainWindow::press);

    connect(ui->difficulty_2, &QPushButton::clicked, this, [=]() { emit play_game(new GamePlay(1, parent, true, 2)); });
    connect(ui->difficulty_2, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),
            &MainWindow::press);

    connect(ui->difficulty_3, &QPushButton::clicked, this, [=]() { emit play_game(new GamePlay(1, parent, true, 3)); });
    connect(ui->difficulty_3, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),
            &MainWindow::press);

    connect(this, &GameSelect::play_game, dynamic_cast<MainWindow *>(parent->parentWidget()), &MainWindow::game_play);
    connect(ui->back_button, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),
            &MainWindow::game_start);
    connect(ui->back_button, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),
            &MainWindow::press);
}

GameSelect::~GameSelect() {
    delete ui;
}
