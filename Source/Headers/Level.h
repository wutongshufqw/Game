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

class Level {
private:
    int level;
    QTime time;
    int size[2];
    int num;
    struct Line{
        QPoint start;
        QPoint end;
    };
    Line *lines;
public:
    Level(int number);
    void write();
    void read(const QString& path);
};


#endif //GAME_LEVEL_H
