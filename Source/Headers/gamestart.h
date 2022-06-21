//
// Created by 24157 on 2022/6/21.
//

#ifndef GAME_GAMESTART_H
#define GAME_GAMESTART_H

#include <QWidget>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class GameStart; }
QT_END_NAMESPACE

class GameStart : public QWidget {
Q_OBJECT

public:
    explicit GameStart(QWidget *parent = nullptr);

    ~GameStart() override;

private:
    Ui::GameStart *ui;
};


#endif //GAME_GAMESTART_H
