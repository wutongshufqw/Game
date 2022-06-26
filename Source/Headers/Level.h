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
    int level{};
    QTime time;
    int size[2]{};
    int num{};
    Line *lines{};

private:
    QString path;

public:
    void setLines(Line *lines);

    __attribute__((unused)) int getLevel() const;

    const QTime &getTime() const;

    const int *getSize() const;

    int getNum() const;

    Line *getLines() const;

    void setTime(const QTime &qTime);

    explicit Level(int number);

    Level(int difficulty, int level, bool create = false);

    void read();

    void write();

    ~Level();
};


#endif //GAME_LEVEL_H
