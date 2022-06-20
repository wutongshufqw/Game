//
// Created by y on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GamePlay.h" resolved

#include "gameplay.h"
#include "Forms/ui_GamePlay.h"


GamePlay::GamePlay(QWidget *parent) :
        QWidget(parent), ui(new Ui::GamePlay) {
    ui->setupUi(this);
}

GamePlay::~GamePlay() {
    delete ui;
}
