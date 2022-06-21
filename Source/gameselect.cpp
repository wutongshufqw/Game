//
// Created by 26412 on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameSelect.h" resolved

#include "Headers/gameselect.h"
#include "Forms/ui_gameselect.h"


GameSelect::GameSelect(QWidget *parent) :
        QWidget(parent), ui(new Ui::GameSelect) {
    ui->setupUi(this);
}

GameSelect::~GameSelect() {
    delete ui;
}
