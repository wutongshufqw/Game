//
// Created by 26412 on 2022/6/20.
//

#ifndef GAME_GAMESELECT_H
#define GAME_GAMESELECT_H

#include <QWidget>
#include "gameplay.h"
#include "mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GameSelect; }
QT_END_NAMESPACE

class GameSelect : public QWidget {

public:
    explicit GameSelect(QWidget *parent, QMainWindow *mainWindow);

    ~GameSelect() override;

public slots:
    void playGame_1();

private:
    Ui::GameSelect *ui;
    GamePlay *gamePlay;
    QMainWindow *mainWindow;
};


#endif //GAME_GAMESELECT_H
