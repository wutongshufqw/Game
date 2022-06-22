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

public:
    explicit GamePlay(QWidget *parent = nullptr);

    ~GamePlay() override;

public slots:

private:
    Ui::GamePlay *ui;
};


#endif //GAME_GAMEPLAY_H
