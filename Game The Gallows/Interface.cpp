#include "Interface.h"
#include "Statics.h"
#include "HangmanGame.h"

void HangmanGameEngine::run()
{
    while (true) 
    {
        system("cls");

        cout << "Слово: " << game.displayWord() << endl;

        cout << "Введите букву: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (find(game.guessedLetters.begin(), game.guessedLetters.end(), guess) != game.guessedLetters.end()) 
        {
            cout << "Вы уже вводили эту букву. Попробуйте другую." << endl;
            continue;
        }

        game.attempts++; 
        game.guessedLetters.push_back(guess);

        if (game.displayWord() == game.secretWord) 
        {
            cout << "Поздравляю! Вы угадали слово: " << game.secretWord << endl;

            game.endTime = time(nullptr);
            GameStatistics::print(game);
            break;
        }
        else if (game.attempts >= 10) 
        {
            cout << "Извините, вы проиграли. Искомое слово было: " << game.secretWord << endl;

            game.endTime = time(nullptr);
            GameStatistics::print(game);
            break;
        }
    }
}

