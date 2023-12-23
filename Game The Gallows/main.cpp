#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "HangmanGame.h"
#include "Interface.h"


using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");

    try {
        HangmanGame game("wordlist.txt"); 
        HangmanGameEngine manager(game); 
        manager.run(); 
    } 
    catch (const runtime_error& e) 
    {
        cout << e.what() << endl; 
    }

    return 0;
}