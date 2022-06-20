//
// Created by 26412 on 2022/6/20.
//

#ifndef GAME_GAMESELECT_H
#define GAME_GAMESELECT_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class GameSelect; }
QT_END_NAMESPACE

class GameSelect : public QWidget {
Q_OBJECT

public:
    explicit GameSelect(QWidget *parent = nullptr);

    ~GameSelect() override;

private:
    Ui::GameSelect *ui;
};


#endif //GAME_GAMESELECT_H
