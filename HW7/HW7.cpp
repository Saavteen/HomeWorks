
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int main()
{
    bool exitCondition = false;
    const int generationRange = 3;
    int rounds;
    srand(std::time(0));
    std::cout << "hello\n\n";

    
  int loseRound = 0 , winRound = 0, drawRound = 0, totalTries = 0;
    while (!exitCondition)
    {
        std::cout << "Enter ammount of round :  or -1 to exit ";
        std::cin >> rounds;
        

        //exit
        if (rounds == -1)
        {
            std::cout << "Bye !";
            exitCondition = true;
        }


        int roundTries=0;
        
        //Rounds
        while (roundTries < rounds)
        {
            int randomNumber = std::rand() % (generationRange) +1;
            char YourAction,ComputerAction;
            switch (randomNumber)
            {
            case 1:
                ComputerAction = 'R';
                    break;
            case 2:
                ComputerAction = 'S';
                    break;
            case 3:
                ComputerAction = 'P';
                    break;
            }
            //input your action
            //std::cout << randomNumber << "\n";
            std::cout << "Input R S P : \n";
            std::cin >> YourAction;

            //Finding round conditions
            if (ComputerAction == 'R')
            {
                if (YourAction == 'R')
                {
                    std::cout << "Draw!\n";
                    drawRound++;
                }
                else if (YourAction == 'S')
                {
                    std::cout << "lose!\n";
                    loseRound++;
                }
                else
                {
                    std::cout << "win!!!\n";
                    winRound++;
                }
            }
            else if (ComputerAction == 'S')
            {
                if (YourAction == 'S')
                {
                    std::cout << "Draw!\n";
                    drawRound++;
                }
                else if (YourAction == 'P')
                {
                    std::cout << "lose!\n";
                    loseRound++;
                }
                else
                {
                    std::cout << "win!!!\n";
                    winRound++;
                }
            }
            else
            {
                if (YourAction == 'P')
                {
                    std::cout << "Draw!\n";
                    drawRound++;
                }
                else if (YourAction == 'R')
                {
                    std::cout << "lose!\n";
                    loseRound++;
                }
                else
                {
                    std::cout << "win!!!\n";
                    winRound++;
                }
            }
            roundTries++;
            totalTries++;
        }

            //statistic
            std::cout << "Stats \n";
            std::cout << "Total Rounds :" << totalTries << "\n";
            std::cout << "Win Rounds :" << winRound << "\n";
            std::cout << "Lose Rounds :" << loseRound << "\n";
            std::cout << "Draw Rounds :" << drawRound << "\n";

    }
    return 0;
 }
