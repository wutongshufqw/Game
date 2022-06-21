//
// Created by y on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GamePlay.h" resolved

#include <QPushButton>
#include <QFile>
#include "gameplay.h"
#include "Forms/ui_GamePlay.h"


GamePlay::GamePlay(QWidget *parent) :
        QWidget(parent), ui(new Ui::GamePlay) {
    ui->setupUi(this);
    setFixedSize(QSize(1280, 800));
    setWindowTitle("第1关");
    QFile GPQss(":/qss/gameplay.qss");
    if (GPQss.open(QFile::ReadOnly))
        this->setStyleSheet(GPQss.readAll());
    ui->minumTime->setText("最快用时\n00:00:00");
    ui->nowTime->setText("当前用时\n00:00:00");
    connect(ui->back, &QPushButton::clicked, this, &GamePlay::back_clicked);
}

GamePlay::~GamePlay() {
    delete ui;
}

void GamePlay::restart_clicked() {
    qDebug("restart");
}

void GamePlay::submit_clicked() {
    qDebug("submit");
}

void GamePlay::back_clicked() {
    this->close();
}
