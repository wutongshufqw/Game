//
// Created by y on 2022/6/22.
//

#include "Level.h"

Level::Level(int number) {
    QString path = QString(":/level/level%1.txt").arg(number);
    read(path);
}

void Level::read(const QString& path) {
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        stream >> level;
        QString time_str;
        stream >> time_str;
        time = QTime::fromString(time_str, "hh:mm:ss");
        stream >> size;
        stream >> num;
        lines = new Line[num];
        for(int i = 0; i < num; i++){
            int x1, y1, x2, y2;
            stream >> x1 >> y1 >> x2 >> y2;
            lines[i]={QPoint(x1, y1), QPoint(x2, y2)};
        }
        file.close();
        qDebug() << level << time << size << num;
        for(int i = 0; i < num; i++){
            qDebug() << lines[i].start << lines[i].end;
        }
    }else{
        qDebug() << "open file failed";
    }
}
