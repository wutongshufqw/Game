//
// Created by y on 2022/6/26.
//

#include "GameCreator.h"

GameCreator::GameCreator(int difficulty, int level) {
    this->level = new Level(difficulty, level, true);
    Line *lines = new Line[this->level->getNum()];
    std::vector<QPoint> vector;
    srand((unsigned)clock());
    int beg = (rand()%(8-0+1));
    for(int i = 0; i <this->level->getNum();i++){
        while(true){
            int en = (rand()%(8-0+1));
            if(en==beg)
                continue;
            if(std::count(vector.begin(),vector.end(),QPoint(beg,en)))
                continue;
            vector.push_back(QPoint(beg,en));
            lines[i]={{beg/this->level->getSize()[1],beg%this->level->getSize()[1]},{en/this->level->getSize()[1],en%this->level->getSize()[1]}};
            beg = en;
            break;
        }
    }
    this->level->setLines(lines);
    this->level->write();
    delete this->level;
}
