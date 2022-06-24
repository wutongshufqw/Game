//
// Created by y on 2022/6/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameShow.h" resolved

#include "gameshow.h"
#include "Forms/ui_GameShow.h"
#include <QPainter>
#include <QMouseEvent>
#include <cmath>

GameShow::GameShow(Level *level, QWidget *parent) :
        QWidget(parent), ui(new Ui::GameShow), level(level) {
    ui->setupUi(this);
    setFixedSize(QSize(780, 780));

    topLeft = QPoint((int)(this->width()*0.05),(int)(this->height()*0.05));
    bottomRight = QPoint((int)(this->width()*0.95),(int)(this->height()*0.95));

    wid = (bottomRight.x() - topLeft.x())/level->getSize()[1];
    hei = (bottomRight.y() - topLeft.y())/level->getSize()[0];
    double rd = fmin(wid, hei);

    round0 = (int)(rd * 0.25);
    round1 = (int)(rd * 0.2);
    round2 = (int)(rd * 0.09);
    round3 = (int)(rd * 0.05);

    //i--行数
    //j--列数
    points = new QPoint[level->getSize()[0]*level->getSize()[1]];
    for(int i = 0; i < level->getSize()[0]; i++)
        for(int j = 0; j < level->getSize()[1]; j++)
            points[i*level->getSize()[1] + j] = QPoint((int)((2 * topLeft.x() + (2 * j + 1) * wid) / 2), (int)((2 * topLeft.y() + (2 * i + 1) * hei) / 2)),
            flag[i*level->getSize()[1] + j] = false;

    lines = level->getLines();
    correct = new bool[level->getNum()];
    for(int i = 0; i < level->getNum(); i++)
        flag[lines[i].start.x()*level->getSize()[1] + lines[i].start.y()] = flag[lines[i].end.x()*level->getSize()[1] + lines[i].end.y()] = true, correct[i] = false;
}

GameShow::~GameShow() {
    delete ui;
}

void GameShow::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen0 = QPen(QColor(255, 255, 255, 127), 1);
    QBrush brush0 = QBrush(QColor(255, 255, 255, 127));

    QPen pen1 = QPen(Qt::gray, 10);
    pen1.setCapStyle(Qt::RoundCap);
    pen1.setJoinStyle(Qt::RoundJoin);
    QPen pen1_1 = QPen(QColor(0,191,95), 10);
    pen1_1.setCapStyle(Qt::RoundCap);
    pen1_1.setJoinStyle(Qt::RoundJoin);
    QPen pen1_2 = QPen(QColor(219,61,61), 10);
    pen1_2.setCapStyle(Qt::RoundCap);
    pen1_2.setJoinStyle(Qt::RoundJoin);

    QPen pen2 = QPen(QColor(206,200,200), 1);
    QBrush brush2 = QBrush(QColor(206,200,200));
    QPen pen2_1 = QPen(QColor(152,249,152), 1);
    QBrush brush2_1 = QBrush(QColor(152,249,152));
    QPen pen2_2 = QPen(QColor(247,138,138), 1);
    QBrush brush2_2 = QBrush(QColor(247,138,138));

    QPen pen3 = QPen(Qt::gray, 1);
    QBrush brush3 = QBrush(Qt::gray);
    QPen pen3_1 = QPen(QColor(0,191,95), 1);
    QBrush brush3_1 = QBrush(QColor(0,191,95));
    QPen pen3_2 = QPen(QColor(219,61,61), 1);
    QBrush brush3_2 = QBrush(QColor(219,61,61));

    QPen pen4 = QPen(Qt::white, 1);
    QBrush brush4 = QBrush(Qt::white);

    //底部圆圈
    for(int i = 0; i < level->getSize()[0]*level->getSize()[1]; i++) {
        painter.setPen(pen0);
        painter.setBrush(brush0);
        painter.drawEllipse(points[i], round0, round0);

        painter.setPen(pen2);
        painter.setBrush(brush2);
        painter.drawEllipse(points[i], round1, round1);


        painter.setPen(pen3);
        painter.setBrush(brush3);
        painter.drawEllipse(points[i], round2, round2);

    }

    //红色圆
    for(auto red_line : red_lines) {
        painter.setPen(pen2_2);
        painter.setBrush(brush2_2);
        painter.drawEllipse(points[red_line.start.x()*level->getSize()[1] + red_line.start.y()], round1, round1);
        painter.drawEllipse(points[red_line.end.x()*level->getSize()[1] + red_line.end.y()], round1, round1);
        painter.setPen(pen3_2);
        painter.setBrush(brush3_2);
        painter.drawEllipse(points[red_line.start.x()*level->getSize()[1] + red_line.start.y()], round2, round2);
        painter.drawEllipse(points[red_line.end.x()*level->getSize()[1] + red_line.end.y()], round2, round2);
    }

    //绿色圆
    for(auto green_line : green_lines) {
        painter.setPen(pen2_1);
        painter.setBrush(brush2_1);
        painter.drawEllipse(points[green_line.start.x()*level->getSize()[1] + green_line.start.y()], round1, round1);
        painter.drawEllipse(points[green_line.end.x()*level->getSize()[1] + green_line.end.y()], round1, round1);
        painter.setPen(pen3_1);
        painter.setBrush(brush3_1);
        painter.drawEllipse(points[green_line.start.x()*level->getSize()[1] + green_line.start.y()], round2, round2);
        painter.drawEllipse(points[green_line.end.x()*level->getSize()[1] + green_line.end.y()], round2, round2);
    }

    //当前圆
    if(now != -1){
        if(flag[now]) {
            painter.setPen(pen2_1);
            painter.setBrush(brush2_1);
            painter.drawEllipse(points[now], round1, round1);
            painter.setPen(pen3_1);
            painter.setBrush(brush3_1);
            painter.drawEllipse(points[now], round2, round2);
        }else{
            painter.setPen(pen2_2);
            painter.setBrush(brush2_2);
            painter.drawEllipse(points[now], round1, round1);
            painter.setPen(pen3_2);
            painter.setBrush(brush3_2);
            painter.drawEllipse(points[now], round2, round2);
        }
    }

    //绘制连线
    for(int i = 0; i < level->getNum(); i++){
        painter.setPen(pen1);
        painter.setBrush(QBrush(Qt::NoBrush));
        QPoint start = points[lines[i].start.x()*level->getSize()[1] + lines[i].start.y()];
        QPoint end = points[lines[i].end.x()*level->getSize()[1] + lines[i].end.y()];
        painter.drawLine(start, end);
    }

    //红色连线
    for(auto red_line : red_lines) {
        painter.setPen(pen1_2);
        painter.setBrush(QBrush(Qt::NoBrush));
        QPoint start = points[red_line.start.x()*level->getSize()[1] + red_line.start.y()];
        QPoint end = points[red_line.end.x()*level->getSize()[1] + red_line.end.y()];
        painter.drawLine(start, end);
    }

    //绿色连线
    for(auto green_line : green_lines) {
        painter.setPen(pen1_1);
        painter.setBrush(QBrush(Qt::NoBrush));
        QPoint start = points[green_line.start.x()*level->getSize()[1] + green_line.start.y()];
        QPoint end = points[green_line.end.x()*level->getSize()[1] + green_line.end.y()];
        painter.drawLine(start, end);
    }

    //当前连线
    if(now != -1) {
        if(flag[now])
            painter.setPen(pen1_1);
        else
            painter.setPen(pen1_2);
        painter.setBrush(QBrush(Qt::NoBrush));
        painter.drawLine(points[now], nowPoint);
    }

    //顶部画圆
    for(int i = 0; i < level->getSize()[0]*level->getSize()[1]; i++) {
        painter.setPen(pen4);
        painter.setBrush(brush4);
        painter.drawEllipse(points[i], round3, round3);
    }
}

void GameShow::mousePressEvent(QMouseEvent *event) {
    if(temp!=-1)
        now = temp;
    else
        now = inCircle(event->pos());
    nowPoint = event->pos();
    update();
}

void GameShow::mouseMoveEvent(QMouseEvent *event) {
    nowPoint = event->pos();
    if(now!=-1 && inCircle(event->pos()) != -1 && now != inCircle(event->pos())) {
        if(!existence({QPoint(now / level->getSize()[1], now % level->getSize()[1]),
                       QPoint(inCircle(event->pos()) / level->getSize()[1],
                              inCircle(event->pos()) % level->getSize()[1])})) {
            last = now;
            now = inCircle(event->pos());
            if(inLine(last, now)!= -1) {
                correct[inLine(last, now)] = true;
                green_lines.push_back({QPoint(last / level->getSize()[1], last % level->getSize()[1]),
                                       QPoint(now / level->getSize()[1], now % level->getSize()[1])});
            }else{
                red_lines.push_back({QPoint(last / level->getSize()[1], last % level->getSize()[1]),
                                     QPoint(now / level->getSize()[1], now % level->getSize()[1])});
            }
        }
    }else if(!flag1 && inCircle(event->pos())!=-1){
        flag1 = true;
        now = inCircle(event->pos());
    }
    update();
}

void GameShow::mouseReleaseEvent(QMouseEvent *event) {
    temp= now;
    now = -1;
    update();
}

int GameShow::inCircle(const QPoint &point) {
    for(int i = 0; i < level->getSize()[0]*level->getSize()[1]; i++) {
        if(sqrt(pow(point.x() - points[i].x(), 2) + pow(point.y() - points[i].y(), 2)) <= round1)
            return i;
    }
    return -1;
}

int GameShow::inLine(int a, int b){
    for(int i = 0; i < level->getNum(); i++){
        if(lines[i].start.x() == a/level->getSize()[1] && lines[i].start.y() == a%level->getSize()[1] &&
           lines[i].end.x() == b/level->getSize()[1] && lines[i].end.y() == b%level->getSize()[1])
            return i;
        if(lines[i].start.x() == b/level->getSize()[1] && lines[i].start.y() == b%level->getSize()[1] &&
           lines[i].end.x() == a/level->getSize()[1] && lines[i].end.y() == a%level->getSize()[1])
            return i;
    }
    return -1;
}

bool GameShow::existence(Line l) {
    for(auto & green_line : green_lines){
        if(green_line.start.x() == l.start.x() && green_line.start.y() == l.start.y() &&
           green_line.end.x() == l.end.x() && green_line.end.y() == l.end.y())
            return true;
        if(green_line.start.x() == l.end.x() && green_line.start.y() == l.end.y() &&
           green_line.end.x() == l.start.x() && green_line.end.y() == l.start.y())
            return true;
    }
    for(auto & red_line : red_lines){
        if(red_line.start.x() == l.start.x() && red_line.start.y() == l.start.y() &&
           red_line.end.x() == l.end.x() && red_line.end.y() == l.end.y())
            return true;
        if(red_line.start.x() == l.end.x() && red_line.start.y() == l.end.y() &&
           red_line.end.x() == l.start.x() && red_line.end.y() == l.start.y())
            return true;
    }
    return false;
}

bool GameShow::finish() {
    if(!red_lines.empty())
        return false;
    for(int i = 0; i < level->getNum(); i++)
        if(!correct[i])
            return false;
    return true;
}
