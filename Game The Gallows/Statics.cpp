#include "Statics.h"

void GameStatistics::print(const HangmanGame& game)
{
    cout << "Статистика игры:" << endl;
    cout << "Время: " << difftime(game.endTime, game.startTime) << " секунд" << endl;
    cout << "Количество попыток: " << game.attempts << endl;
    cout << "Искомое слово: " << game.secretWord << endl;
    cout << "Буквы игрока: ";

    for (char letter : game.guessedLetters) 
    {
        cout << letter << ' ';
    }
    cout << endl;
}
