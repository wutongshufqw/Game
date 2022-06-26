//
// Created by y on 2022/6/26.
//

#ifndef GAME_GAMECREATOR_H
#define GAME_GAMECREATOR_H


#include "Level.h"
#include "gameshow.h"

class GameCreator {
public:
    GameCreator(int difficulty, int level);
private:
    Level *level;
};


#endif //GAME_GAMECREATOR_H
