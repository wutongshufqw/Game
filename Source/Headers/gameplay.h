//
// Created by y on 2022/6/20.
//

#ifndef GAME_GAMEPLAY_H
#define GAME_GAMEPLAY_H

#include <QWidget>
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include "Level.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GamePlay; }
QT_END_NAMESPACE

class GamePlay : public QWidget {
Q_OBJECT

public:
    explicit GamePlay(int level, QWidget *parent = nullptr);

    ~GamePlay() override;

public slots:

    void submit();

    void back();

    void restart();

    void nextLevel();

    void update_();

private:
    Ui::GamePlay *ui;
    int level;
    QTimer *timer;
    QTime time;
    Level *level_;
    QWidget *gameShow;
};


#endif //GAME_GAMEPLAY_H
