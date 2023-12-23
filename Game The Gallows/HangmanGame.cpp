#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <Windows.h>
#include "HangmanGame.h"

using namespace std;

void HangmanGame::loadWords(const string& filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        throw runtime_error("Не удалось открыть файл с словами.");
    }

    string word;
    while (file >> word) //цикл, пока считываются слова
    {
        wordList.push_back(word);
    }
    file.close();
}

void HangmanGame::chooseRandomWord()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % wordList.size();
    secretWord = wordList[index];
}

string HangmanGame::displayWord() const
{
    string displayedWord(secretWord.length(), '_');

    for (size_t i = 0; i < secretWord.length(); ++i)
    {
        if (find(guessedLetters.begin(), guessedLetters.end(), secretWord[i]) != guessedLetters.end())
        {
            displayedWord[i] = secretWord[i];
        }
    }
    return displayedWord;
}

