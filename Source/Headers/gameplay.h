//
// Created by y on 2022/6/20.
//

#ifndef GAME_GAMEPLAY_H
#define GAME_GAMEPLAY_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class GamePlay; }
QT_END_NAMESPACE

class GamePlay : public QWidget {
Q_OBJECT

public:
    explicit GamePlay(QWidget *parent = nullptr);

    ~GamePlay() override;

private:
    Ui::GamePlay *ui;
};


#endif //GAME_GAMEPLAY_H
