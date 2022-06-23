//
// Created by y on 2022/6/21.
//

#ifndef GAME_MAINWINDOW_H
#define GAME_MAINWINDOW_H

#define MAX_LEVEL 3

#include <QMainWindow>
#include "gamestart.h"
#include "gameselect.h"
#include "gameplay.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QApplication *app, QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:

    void game_start();

    void game_select();

    void game_play(QWidget *);

    void restart();

private:
    Ui::MainWindow *ui;
    QApplication *app;
    QWidget *gameStart;
    QWidget *gameSelect;
    QWidget *gamePlay = nullptr;
    QWidget *centre;
};


#endif //GAME_MAINWINDOW_H
