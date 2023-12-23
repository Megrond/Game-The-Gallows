#pragma once
#include "HangmanGame.h"

class HangmanGameEngine
{
private:
    HangmanGame& game; 

public:
    HangmanGameEngine(HangmanGame& game) : game(game) {}
    void run();  
};
