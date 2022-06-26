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
#include "gameshow.h"
#include "GameCreator.h"


GamePlay::GamePlay(int level, QWidget *parent, bool ai, int difficulty) :
        QWidget(parent), ui(new Ui::GamePlay), level(level), ai(ai), difficulty(difficulty) {
    ui->setupUi(this);

    setFixedSize(QSize(1280, 800));
    setAttribute(Qt::WA_DeleteOnClose);

    QFile GPQss(":/qss/qss/gameplay.qss");
    if (GPQss.open(QFile::ReadOnly))
        this->setStyleSheet(GPQss.readAll());

    if(ai){
        GameCreator(difficulty,level);
        level_ = new Level(difficulty,level);
    }
    else
        level_ = new Level(level);


    time.setHMS(0, 0, 0, 0);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GamePlay::update_);
    timer->start(1000);

    ui->minumTime->setText("最快用时\n" + level_->getTime().toString("hh:mm:ss"));
    ui->nowTime->setText("当前用时\n00:00:00");
    ui->level->setText(QString("第%1%2").arg(level).arg("关"));

    gameShow = new GameShow(level_, ui->game);

    connect(ui->back, &QPushButton::clicked, this, &GamePlay::close);
    connect(ui->back, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),
            &MainWindow::game_select);
    connect(ui->back, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),&MainWindow::press);

    connect(ui->step_back, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()), &MainWindow::press);
    connect(ui->step_back, &QPushButton::clicked, dynamic_cast<GameShow*>(gameShow), &GameShow::stepBack);

    connect(ui->submit, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),&MainWindow::press);
    connect(ui->submit, &QPushButton::clicked, this, &GamePlay::submit);

    connect(ui->restart, &QPushButton::clicked, this, &GamePlay::restart);
    connect(ui->restart, &QPushButton::clicked, dynamic_cast<MainWindow *>(parent->parentWidget()),&MainWindow::press);

}

GamePlay::~GamePlay() {
    delete ui;
}

void GamePlay::submit() {
    timer->stop();
    if(dynamic_cast<GameShow*>(gameShow)->finish()) {
        GameComplete gameComplete(level < MAX_LEVEL, true, time.toString(), this);
        level_->setTime(time);
        level_->write();
        gameComplete.exec();
    } else {
        GameComplete gameComplete(level < MAX_LEVEL, false, time.toString(), this);
        gameComplete.exec();
    }
}

void GamePlay::back() {
    emit ui->back->clicked();
}

void GamePlay::restart() {
    this->close();
    if(ai)
        dynamic_cast<MainWindow *>(this->parentWidget()->parentWidget())->game_play(
                new GamePlay(level, this->parentWidget(), true, difficulty));
    else
        dynamic_cast<MainWindow *>(this->parentWidget()->parentWidget())->game_play(
                new GamePlay(level, this->parentWidget()));
}

void GamePlay::nextLevel() {
    this->close();
    if(ai)
        dynamic_cast<MainWindow *>(this->parentWidget()->parentWidget())->game_play(
                new GamePlay(++level, this->parentWidget(),true, difficulty));
    else
        dynamic_cast<MainWindow *>(this->parentWidget()->parentWidget())->game_play(
                new GamePlay(++level, this->parentWidget()));
}

void GamePlay::update_() {
    static quint32 time_out = 0;
    time_out++;
    time = time.addSecs(1);
    ui->nowTime->setText("当前用时\n" + time.toString("hh:mm:ss"));
}
