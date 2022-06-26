//
// Created by y on 2022/6/22.
//

#ifndef GAME_GAMECOMPLETE_H
#define GAME_GAMECOMPLETE_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class GameComplete; }
QT_END_NAMESPACE

class GameComplete : public QDialog {
Q_OBJECT

public:
    explicit GameComplete(bool nextLevel, bool flag, const QString &str, QWidget *parent = nullptr);

    ~GameComplete() override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::GameComplete *ui;
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
};


#endif //GAME_GAMECOMPLETE_H
