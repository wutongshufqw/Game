//
// Created by 26412 on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameSelect.h" resolved

#include "Headers/gameselect.h"
#include "Forms/gameselect.ui"


GameSelect::GameSelect(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameSelect) {
    ui->setupUi(this);
    this->setMinimumSize(QSize(1280, 800));
    this->setMaximumSize(QSize(1280, 800));
}

GameSelect::~GameSelect() {
    delete ui;
}
