#include "Game.h"

int main()
{
    Game game;
    Player player;
    bool IsGameRunning = true;
    while (IsGameRunning)
    {
        game.MainMenu();
        std::cin.clear();
        std::cin.ignore();
    }
    return 0;
}
