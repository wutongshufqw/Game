//
// Created by y on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GamePlay.h" resolved

#include <QPushButton>
#include <QFile>
#include "gameplay.h"
#include "Forms/ui_GamePlay.h"
#include "mainwindow.h"
#include "gamecomplete.h"


GamePlay::GamePlay(int level, QWidget *parent) :
        QWidget(parent), ui(new Ui::GamePlay), level(level) {
    ui->setupUi(this);

    setFixedSize(QSize(1280, 800));
    setAttribute(Qt::WA_DeleteOnClose);

    QFile GPQss(":/qss/qss/gameplay.qss");
    if (GPQss.open(QFile::ReadOnly))
        this->setStyleSheet(GPQss.readAll());

    level_ = new Level(level);

    time.setHMS(0, 0, 0, 0);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GamePlay::update_);
    timer->start(1000);

    ui->minumTime->setText("最快用时\n00:00:00");
    ui->nowTime->setText("当前用时\n00:00:00");
    ui->level->setText(QString("第%1%2").arg(level).arg("关"));

    connect(ui->back, &QPushButton::clicked, this, &GamePlay::close);
    connect(ui->back, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),
            &MainWindow::game_select);
    connect(ui->submit, &QPushButton::clicked, this, &GamePlay::submit);
    connect(ui->restart, &QPushButton::clicked, this, &GamePlay::restart);
}

GamePlay::~GamePlay() {
    delete ui;
}

void GamePlay::submit() {
    timer->stop();
    GameComplete gameComplete(level < MAX_LEVEL, this);
    gameComplete.exec();
}

void GamePlay::back() {
    emit ui->back->clicked();
}

void GamePlay::restart() {
    this->close();
    dynamic_cast<MainWindow *>(this->parentWidget()->parentWidget())->game_play(
            new GamePlay(level, this->parentWidget()));
}

void GamePlay::nextLevel() {
    this->close();
    dynamic_cast<MainWindow *>(this->parentWidget()->parentWidget())->game_play(
            new GamePlay(++level, this->parentWidget()));
}

void GamePlay::update_() {
    static quint32 time_out = 0;
    time_out++;
    time = time.addSecs(1);
    ui->nowTime->setText("当前用时\n"+time.toString("hh:mm:ss"));
}
