//
// Created by y on 2022/6/22.
//

#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <QTime>
#include <QPoint>
#include <QFile>
#include <QTextStream>
#include <QDebug>

struct Line {
    QPoint start;
    QPoint end;
};

class Level {
private:
    int level;
    QTime time;
    int size[2];
    int num;
    Line *lines;
    QString path;
public:
    int getLevel() const;

    const QTime &getTime() const;

    const int *getSize() const;

    int getNum() const;

    Line *const getLines() const;

    void setTime(const QTime &time);

    explicit Level(int number);

    void read();

    void write();

    ~Level();
};


#endif //GAME_LEVEL_H
