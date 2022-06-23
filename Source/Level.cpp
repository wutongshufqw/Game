//
// Created by y on 2022/6/22.
//

#include "Level.h"

Level::Level(int number) {
    path = QString("./level/level%1.txt").arg(number);
    read();
}

void Level::read() {
    QFile file(path);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        stream >> level;
        QString time_str;
        stream >> time_str;
        time = QTime::fromString(time_str, "hh:mm:ss");
        stream >> size[0] >> size[1];
        stream >> num;
        lines = new Line[num];
        for (int i = 0; i < num; i++) {
            int x1, y1, x2, y2;
            stream >> x1 >> y1 >> x2 >> y2;
            lines[i] = {QPoint(x1, y1), QPoint(x2, y2)};
        }
        file.close();
    } else {
        qDebug() << "open file failed";
    }
}

void Level::write(){
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << level << endl;
        stream << time.toString("hh:mm:ss") << endl;
        stream << size[0] << " " << size[1] << endl;
        stream << num << endl;
        for (int i = 0; i < num; i++) {
            stream << lines[i].start.x() << " " << lines[i].start.y() << " " << lines[i].end.x() << " "
                   << lines[i].end.y() << endl;
        }
        file.close();
    } else {
        qDebug() << "open file failed";
    }
}

int Level::getLevel() const {
    return level;
}

const QTime &Level::getTime() const {
    return time;
}

const int *Level::getSize() const {
    return size;
}

int Level::getNum() const {
    return num;
}

Line *const Level::getLines() const {
    return lines;
}

void Level::setTime(const QTime &time) {
    if(time < Level::time)
        Level::time = time;
}

Level::~Level() {
    delete[] lines;
}
