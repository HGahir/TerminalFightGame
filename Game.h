#include "Player.h"

Player player;

class Game
{
    public:

        int DaysPassed;

        void MainMenu()
        {
            bool IsGameRunning = true;
            int PlayerMenuChoice;
            std::cout << "========== Welcome to the Menu ==========" << std::endl;
            std::cout << "1.Start new game" << std::endl;
            std::cout << "2.Continue game" << std::endl;
            std::cout << "3.Edit Player Name" << std::endl;
            std::cout << "0.Quit Game" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "-> ";
            std::cin >> PlayerMenuChoice;
            if (PlayerMenuChoice == 0)
            {
                std::cout << "Quitting Game..." << std::endl;
                IsGameRunning = false;
                return;
            }
            else if (PlayerMenuChoice == 1)
            {
                if (player.PlayerName == "")
                {
                    std::cout << "You must set a valid player name." << std::endl;
                }
                else
                {
                    std::cout << "Starting new game..." << std::endl;
                    GameStart();
                }
            }
            if (PlayerMenuChoice == 2)
            {
                std::cout << "" << std::endl;
            }
            if (PlayerMenuChoice == 3)
            {
                std::cout << "Your current player name is: " << player.PlayerName << std::endl;
                std::cout << "Enter Your new player name here: ";
                std::cin >> player.PlayerName;
                std::cout << "Your new player name is: " << player.PlayerName << std::endl;
            }
            if (PlayerMenuChoice == 8)
            {
                IsGameRunning = false;
                std::cout << "IsGameRunning: " << IsGameRunning << std::endl;
            }
            if (PlayerMenuChoice == 9)
            {
                std::cout << "IsGameRunning: " << IsGameRunning << std::endl;
            }
        }

        void GameStart()
        {
            int PlayerDifficulty;
            player.PlayerEnergy = 100;
            player.PlayerHealth = 100;
            player.PlayerRespect = 0;
            player.PlayerSkill = 0;
            player.PlayerStamina = 10;
            player.PlayerStrength = 10;

            std::cout << "Welcome to the prison fight club " << player.PlayerName << std::endl;
            std::cout << "In this prison winning fights gets you benefits." << std::endl;
            std::cout << "Losing fights will decrease your respect among the other inmates resulting in poor treatment from inmates and prison guards." << std::endl;
            std::cout << "You must train yourself to increase your chances of winning fights, especially as the fights get harder." << std::endl;
            std::cout << "So " << player.PlayerName << "..." << std::endl;
            std::cout << "Lets begin..." << std::endl;

        }

        void GameJailCellIntro()
        {
            std::cout << "Welcome to your jail cell." << std::endl;
            std::cout << "Here you will find all your basic needs like food, water and rest." << std::endl;
            std::cout << "You can train once a day in the GYM to increase your strength, but be mindful of your ENERGY as going to the GYM will take some energy." << std::endl;
        }

        void GameJailCell()
        {
            std::cout << "You are in your JAIL CELL." << std::endl;
            std::cout << "Choose an option: " << std::endl;
            std::cout << "1.Rest" << std::endl;
            std::cout << "2.Go to the Gym" << std::endl;
            std::cout << "3.Shop in the black market" << std::endl;
            int JailCellChoice;
            std::cin >> JailCellChoice;
            bool InJailCell = true;
            while (InJailCell)
            {
                if (JailCellChoice == 1)
                {
                    std::cout << "You curl up into to bed and rest for the night." << std::endl;
                    player.PlayerEnergy = 100;
                    player.PlayerHealth = 100;
                }

                if (JailCellChoice == 2)
                {
                    if (!player.GymVisited)
                    {
                        int PlayerGymChoice;
                        std::cout << "You enter the Gym. What would you like to train?" << std::endl;
                        std::cout << "1.Strength\n2.Stamina\n3.Technique\n4.Leave Gym" << std::endl;
                        std::cin >> PlayerGymChoice;
                        if (PlayerGymChoice == 1)
                        {
                            player.PlayerStrength = player.PlayerStrength + 5;
                            player.GymVisited = true;
                        }
                        if (PlayerGymChoice == 2)
                        {
                            player.PlayerStamina = player.PlayerStamina + 5;
                            player.GymVisited = true;
                        }
                    }
                }
            }
        }

        void DifficultySet(int SetDifficulty)
        {
            
        }

        void FightMode()
        {
            int OpponentStrength = 10;
            int OpponentHealth = 100;
            int OpponentStamina = 10;

            int FightStart;
            bool FightEnd;

            std::cout << "Start Fight?" << std::endl;
            std::cin >> FightStart;
            std::cout >> "" >> std::endl;

            
        }
};
