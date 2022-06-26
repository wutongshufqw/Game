#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
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

#pragma clang diagnostic push
#pragma ide diagnostic ignored "NullDereference"

void Level::write() {
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

#pragma clang diagnostic pop

__attribute__((unused)) int Level::getLevel() const {
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

Line *Level::getLines() const {
    return lines;
}

void Level::setTime(const QTime &qTime) {
    if (qTime < Level::time)
        Level::time = qTime;
}

Level::~Level() {
    delete[] lines;
}

Level::Level(int difficulty, int level, bool create) {
    path = QString("./level/difficulty%1-%2.txt").arg(difficulty).arg(level);
    if (create) {
        this->level = level;
        time.setHMS(11, 59, 59, 999);
        size[0] = difficulty + 2, size[1] = difficulty + 2;
        srand((unsigned) clock());
        switch (difficulty) {
            case 1:
                num = (rand() % (15 - 6 + 1)) + 6;
                break;
            case 2:
                num = (rand() % (30 - 10 + 1)) + 10;
                break;
            case 3:
                num = (rand() % (50 - 20 + 1)) + 20;
                break;
            default:
                break;
        }
    } else {
        read();
    }
}

void Level::setLines(Line *l) {
    Level::lines = l;
}

#pragma clang diagnostic pop