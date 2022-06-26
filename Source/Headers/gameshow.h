//
// Created by y on 2022/6/23.
//

#ifndef GAME_GAMESHOW_H
#define GAME_GAMESHOW_H

#include <QWidget>
#include "Level.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GameShow; }
QT_END_NAMESPACE

class GameShow : public QWidget {
Q_OBJECT

public:
    explicit GameShow(Level *level, QWidget *parent, bool ai = false);

    bool finish();

    void stepBack();

    ~GameShow() override;


private:
    Ui::GameShow *ui{};
    Level *level{};

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    int inCircle(const QPoint &point);

    int inLine(int a, int b);

    bool existence(Line l);

    QPoint *points{};
    QPoint topLeft;
    QPoint bottomRight;

    double wid{};
    double hei{};

    int round0{};
    int round1{};
    int round2{};
    int round3{};

    int now = -1;
    int last = -1;
    int temp = -1;

    std::map<int, bool> flag;
    std::map<int, bool> line;
    bool *correct{};
    bool flag1 = false;

    Line *lines{};
    std::list<Line> red_lines;
    std::list<Line> green_lines;

    std::list<bool> step;

    QPoint nowPoint;

    bool ai;
};


#endif //GAME_GAMESHOW_H
