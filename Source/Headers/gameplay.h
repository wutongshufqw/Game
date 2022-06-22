//
// Created by y on 2022/6/20.
//

#ifndef GAME_GAMEPLAY_H
#define GAME_GAMEPLAY_H

#include <QWidget>
#include <QMainWindow>


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

private:
    Ui::GamePlay *ui;
    int level;
};


#endif //GAME_GAMEPLAY_H
