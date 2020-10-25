#include "Player.h"
#include <stdlib.h>

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
            std::cout << "4.Fight Debug" << std::endl; //Tests the fight function
            std::cout << "0.Quit Game" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "-> ";
            std::cin >> PlayerMenuChoice;
            while (IsGameRunning)
            {
                if (PlayerMenuChoice == 0)
                {
                    std::cout << "Quitting Game..." << std::endl;
                    IsGameRunning = false;
                    exit(0);
                }
                else if (PlayerMenuChoice == 1)
                {
                    if (player.PlayerName == "")
                    {
                        std::cout << "You must set a valid player name." << std::endl;
                        return;
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
                    return;
                }
                if (PlayerMenuChoice == 4)
                {
                    FightMode();
                }
                if (PlayerMenuChoice == 8)
                {
                    IsGameRunning = false;
                    std::cout << "IsGameRunning: " << IsGameRunning << std::endl;
                    return;
                }
                if (PlayerMenuChoice == 9)
                {
                    std::cout << "IsGameRunning: " << IsGameRunning << std::endl;
                    return;
                }
            }
        }

        void GameStart()
        {
            player.PlayerEnergy = 100;
            player.PlayerHealth = 100;
            player.PlayerSpeed = 10;
            player.PlayerRespect = 0;
            player.PlayerSkill = 0;
            player.PlayerStamina = 10;
            player.PlayerStrength = 10;
            std::string PlayerStartCommand;

            std::cout << "Welcome to the prison fight club " << player.PlayerName << std::endl;
            std::cout << "In this prison winning fights gets you benefits." << std::endl;
            std::cout << "Losing fights will decrease your respect among the other inmates resulting in poor treatment from inmates and prison guards." << std::endl;
            std::cout << "You must train yourself to increase your chances of winning fights, especially as the fights get harder." << std::endl;
            std::cout << "So " << player.PlayerName << "..." << std::endl;
            std::cout << "Are you ready to begin?" << std::endl;
            std::cout << "Type 'Yes' to begin" << std::endl;
            std::cout << "-> ";
            std::cin >> PlayerStartCommand;

            if (PlayerStartCommand == "Yes")
            {
                GameJailCellIntro();
            }
            if (PlayerStartCommand == "0")
            {
                exit(0);
            }
            else
            {
                std::cout << "Invalid input. Try Again" << std::endl;
                std::cout << "If you would like to quit type '0'." << std::endl;
                GameStart();
            }
        }

        void GameJailCellIntro()
        {
            std::cout << "Welcome to your jail cell." << std::endl;
            std::cout << "Here you will find all your basic needs like food, water and rest." << std::endl;
            std::cout << "You can train once a day in the GYM to increase your strength, but be mindful of your ENERGY as going to the GYM will take some energy." << std::endl;
            GameJailCell();
        }

        void GameJailCell()
        {

            int JailCellChoice;
            std::cin >> JailCellChoice;
            bool InJailCell = true;
            while (InJailCell)
            {
            std::cout << "You are in your JAIL CELL." << std::endl;
            std::cout << "Choose an option: " << std::endl;
            std::cout << "1.Rest" << std::endl;
            std::cout << "2.Go to the Gym" << std::endl;
            std::cout << "3.Shop in the black market" << std::endl;
                if (JailCellChoice == 1)
                {
                    std::cout << "You curl up into to bed and rest for the night." << std::endl;
                    player.PlayerEnergy = 100;
                    player.PlayerHealth = 100;
                    return;
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
                            return;
                        }
                        if (PlayerGymChoice == 2)
                        {
                            player.PlayerStamina = player.PlayerStamina + 5;
                            player.GymVisited = true;
                            return;
                        }
                    }
                }
            }
        }

        void FightMode()
        {
            int OpponentStrength = 10;
            int OpponentHealth = 100;
            int OpponentStamina = 10;
            int OpponentSpeed = 10;
            int OpponentMove;

            int FightChoice;
            bool FightEnd = false;
            
            while (!FightEnd)
            {
                std::cout << "Choose your move:" << std::endl;
                std::cout << "1.Punch" << std::endl;
                std::cout << "2.Block" << std::endl;
                std::cout << "3.Dodge" << std::endl;
                std::cout << "4.Throw in the towel" << std::endl;
                std::cin >> FightChoice; std::cout << "" << std::endl;
                OpponentMove = rand()%3;

                if (OpponentHealth < 1)
                {
                    std::cout << "Congratultions you have defeated your opponent!" << std::endl;
                    FightEnd = true;
                }
                if (player.PlayerHealth < 1)
                {
                    std::cout << "You LOSE!" << std::endl;
                    std::cout << "Your opponent has defeated you!" << std::endl;
                    FightEnd == true;
                }
                if (FightChoice == 1)
                {
                    if (OpponentMove == 1)
                    {
                        int PlayerPunchPower = rand()%player.PlayerStrength;
                        int OpponentPunchPower = rand()%OpponentStrength;
                        OpponentHealth = OpponentHealth - PlayerPunchPower;
                        player.PlayerHealth = player.PlayerHealth - OpponentPunchPower;
                        std::cout << "Your punch does " << PlayerPunchPower << " damage!" << std::endl;
                        std::cout << "Your Opponent counter-attacks with a punch and deals: " << OpponentPunchPower << " damage." << std::endl;
                        std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                        std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                    }
                    if (OpponentMove == 2)
                    {
                        int PlayerPunchPower = (rand()%player.PlayerStrength)/2;
                        OpponentHealth = OpponentHealth - PlayerPunchPower;
                        std::cout << "Your opponent BLOCKS your punch and only takes " << PlayerPunchPower << " damage!" << std::endl;
                        std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                        std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                    }
                    if (OpponentMove == 3)
                    {
                        int DodgeDecider = rand()%player.PlayerSpeed - rand()%OpponentSpeed;
                        if (DodgeDecider < 0)
                        {
                            std::cout << "Your opponent DODGES your punch!" << std::endl;
                            std::cout << "No damage dealt." << std::endl;
                            std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                            std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                        }
                        if (DodgeDecider > 0)
                        {
                            int PlayerPunchPower = rand()%player.PlayerStrength;
                            OpponentHealth = OpponentHealth - PlayerPunchPower;
                            std::cout << "Your opponent attempts to DODGE your punch but fails." << std::endl;
                            std::cout << "Your punch does " << PlayerPunchPower << " damage!" << std::endl;
                            std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                            std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                        }
                    }
                }
                if (FightChoice == 2)
                {
                    if (OpponentMove == 1)
                    {
                        int OpponentPunchPower = (rand()%OpponentStrength)/2;
                        player.PlayerHealth = player.PlayerHealth - OpponentPunchPower;
                        std::cout << "You BLOCK your opponents PUNCH!" << std::endl;
                        std::cout << "Your opponent's PUNCH does " << OpponentPunchPower << " damage!" << std::endl;
                        std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                        std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                    }
                    if (OpponentMove == 2)
                    {
                        std::cout << "You both try to BLOCK!" << std::endl;
                        std::cout << "Nothing happens." << std::endl;
                        std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                        std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                    }
                    if (OpponentMove == 3)
                    {
                        std::cout << "Your opponent tries to DODGE but you threw no punch." << std::endl;
                        std::cout << "No damage dealt." << std::endl;
                        std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                        std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                    }
                }
                if (FightChoice == 3)
                {
                    if (OpponentMove = 1)
                    {
                        int DodgeDecider = rand()%player.PlayerSpeed - rand()%OpponentSpeed;

                        if (DodgeDecider > 0)
                        {
                            std::cout << "You successfully DODGE your opponent's PUNCH!" << std::endl;
                            std::cout << "No damage dealt." << std::endl;
                            std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                            std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                        }
                        if (DodgeDecider < 0)
                        {
                            int OpponentPunchPower = rand()%OpponentStrength;
                            player.PlayerHealth = player.PlayerHealth - OpponentPunchPower;
                            std::cout << "You try to DODGE your opponent but you fail!" << std::endl;
                            std::cout << "Your opponent does " << OpponentPunchPower << " damage!" << std::endl;
                            std::cout << "Opponent Health: " << OpponentHealth << std::endl;
                            std::cout << player.PlayerName << "'s Health: " << player.PlayerHealth << std::endl;
                        }
                    }
                }
                if (FightChoice == 4)
                {
                    std::cout << "You THROW IN THE TOWEL!" << std::endl;
                    std::cout << "You LOSE by forfit." << std::endl;
                    FightEnd = true;
                }
                else
                {
                    std::cout << "Invalid move. Try again." << std::endl;
                }
                
            }
        }
};
