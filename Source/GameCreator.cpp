#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
//
// Created by y on 2022/6/26.
//

#include "GameCreator.h"
#include <cmath>

GameCreator::GameCreator(int difficulty, int level) {
    this->level = new Level(difficulty, level, true);
    Line *lines = new Line[this->level->getNum()];
    std::vector<QPoint> vector;
    srand((unsigned) clock());
    int beg = (rand() % (8 - 0 + 1));
    for (int i = 0; i < this->level->getNum(); i++) {
        while (true) {
            int en = (rand() % (int) pow(difficulty + 2, 2));
            if (en == beg)
                continue;
            if (std::count(vector.begin(), vector.end(), QPoint(beg, en)))
                continue;
            if (std::count(vector.begin(), vector.end(), QPoint(en, beg)))
                continue;
            vector.emplace_back(beg, en);
            lines[i] = {{beg / this->level->getSize()[1], beg % this->level->getSize()[1]},
                        {en / this->level->getSize()[1],  en % this->level->getSize()[1]}};
            beg = en;
            break;
        }
    }
    this->level->setLines(lines);
    this->level->write();
    delete this->level;
}

#pragma clang diagnostic pop