//
// Created by y on 2022/6/21.
//

#ifndef GAME_GAMESTART_H
#define GAME_GAMESTART_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class GameStart; }
QT_END_NAMESPACE

class GameStart : public QWidget {

public:
    explicit GameStart(QWidget *parent = nullptr);

    ~GameStart() override;

private:
    Ui::GameStart *ui;
};


#endif //GAME_GAMESTART_H
