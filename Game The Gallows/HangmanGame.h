#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <Windows.h>

using namespace std;

class HangmanGame
{
    friend class GameStatistics;
    friend class HangmanGameEngine;

private:
    vector<string> wordList;
    string secretWord;
    vector<char> guessedLetters;
    int attempts;
    time_t startTime;
    time_t endTime;

    void loadWords(const string& filePath);
    void chooseRandomWord();
    string displayWord() const;



public:
    HangmanGame(const string& filePath) : attempts(0)
    {
        loadWords(filePath);
        chooseRandomWord();
        startTime = time(nullptr);
    }
}; 
