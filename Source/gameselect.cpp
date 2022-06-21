//
// Created by 26412 on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameSelect.h" resolved

#include <QFile>
#include "gameselect.h"
#include "Forms/ui_GameSelect.h"


GameSelect::GameSelect(QWidget *parent, QMainWindow *mainWindow) :
        QWidget(parent), ui(new Ui::GameSelect) {
    ui->setupUi(this);
    this->mainWindow = mainWindow;
    setFixedSize(QSize(1280,800));
    QFile GSQss(":/qss/gameselect.qss");
    if (GSQss.open(QFile::ReadOnly))
        this->setStyleSheet(GSQss.readAll());
    connect(ui->level_1,&QPushButton::clicked, this, &GameSelect::playGame_1);
}

GameSelect::~GameSelect() {
    delete ui;
}

void GameSelect::playGame_1() {
    gamePlay = new GamePlay(this);
    this->hide();
    dynamic_cast<MainWindow*>(mainWindow)->playGame(gamePlay);
}
