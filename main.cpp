#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <string>
#include <cmath>
#include <map>
#include <cstring>
#include <cctype>

int display_opening_menu();
bool generateChessOpening(std::string opening);

int main()
{
    int user_input = display_opening_menu();
    while (user_input < 11)
    {

        bool passTest = true;
        switch (user_input)
        {
        case 1:
        {
            passTest = generateChessOpening("QueensGambitDeclined.txt");
            break;
        }
        case 2:
        {
            passTest = generateChessOpening("KingsGambitAccepted.txt");
            break;
        }
        case 3:
        {
            passTest = generateChessOpening("SicillianNajdorf.txt");
            break;
        }
        case 4:
        {
            passTest = generateChessOpening("LondonSystem.txt");
            break;
        }
        case 5:
        {
            passTest = generateChessOpening("ItalianGame.txt");
            break;
        }
        case 6:
        {
            passTest = generateChessOpening("ScotchGame.txt");
            break;
        }
        case 7:
        {
            passTest = generateChessOpening("DanishGambit.txt");
            break;
        }
        case 8:
        {
            passTest = generateChessOpening("StaffordGambitAccepted.txt");
            break;
        }
        case 9:
        {
            passTest = generateChessOpening("CaroKann.txt");
            break;
        }
        case 10:
        {
            passTest = generateChessOpening("RuyLopez.txt");
            break;
        }
        case 11:
        {
            return 0;
        }
        }

        if (passTest == false)
        {
            std::cout << "You guessed incorrectly\n"
                      << std::endl;
        }
        else
        {
            std::cout << "You know the opening line!!!\n"
                      << std::endl;
        }

        std::cout << std::endl;

        user_input = display_opening_menu();
    }

    return 0;
}

int display_opening_menu()
{
    std::cout << "Choose the following openings to play through: " << std::endl;
    std::cout << "1. Queens Gambit Declined" << std::endl;
    std::cout << "2. Kings Gambit Accepted " << std::endl;
    std::cout << "3. Sicillian Defense, Najdorf Variation  " << std::endl;
    std::cout << "4. London System " << std::endl;
    std::cout << "5. Italian Game " << std::endl;
    std::cout << "6. Scotch Game " << std::endl;
    std::cout << "7. Danish Gambit" << std::endl;
    std::cout << "8. Stafford Gambit Accepted" << std::endl;
    std::cout << "9. Caro-Kann " << std::endl;
    std::cout << "10. Ruy Lopez" << std::endl;
    std::cout << "11. Quit Menu" << std::endl;
    std::cout << std::endl;

    int input;
    std::cin >> input;

    if (input < 1 || input > 11)
    {
        std::cout << "invalid input" << std::endl;
        return 11;
    }

    return input;
}

bool generateChessOpening(std::string opening)
{
    std::vector<std::string> moves;
    std::string move;
    std::ifstream myfile;

    std::cout << "You chose the " << opening << " opening\n"
              << std::endl;

    myfile.open(opening);

    if (myfile.is_open())
    {
        while (myfile >> move)
        {
            // std::cout << "the move being read from the file is: " << move << std::endl;
            // std::cout << "The move being pushed to the vector of strings called move is " << move << std::endl;
            moves.push_back(move);
            // myfile >> move;
            // std::cout << "the next move being read in the file is now: " << move << std::endl;
            // if (myfile.eof())
            // {
            //     moves.push_back(move);
            // }
        }
    }

    std::cout << "Note that this code is sensitive to input. A knight move should be indicated by 'N'. A bishop is 'B'. A queen is 'Q'. King is 'K'." << std::endl;
    std::cout << "If you write nc6 for example as 'knight to c6', the code will give you an error. You must write 'Nc6'. In other words, the input is capital and lowercase sensitive" << std::endl;
    std::cout << "If a piece is taken in the opening, it should be denoted by an 'x'. For example d4 e5 dxe5 means pawn to d4 pawn to e5 and then pawn on d4 takes e5." << std::endl;
    std::cout << "Start guessing the move order! Good luck!\n"
              << std::endl;

    std::cout << "The current moves for this opening is this:\n"
              << std::endl;
    for (int i = 0; i < moves.size(); i++)
    {
        std::cout << "move " << i << " is: " << moves[i] << std::endl;
    }

    bool user_guess = true;
    int move_number = 0;
    std::string move_guess;
    while (user_guess && move_number < moves.size())
    {
        std::cout << "Move " << move_number << " is: ";
        std::cin >> move_guess;

        if (move_guess != moves[move_number])
        {
            std::cout << "That is not the correct move for this line. Try again" << std::endl;
            return false;
        }

        if (move_number != moves.size() - 1)
        {
            std::cout << "Correct!"
                      << " The next move for black is : " << moves[move_number + 1] << std::endl;
            move_number += 2;
        }
    }
    return true;
}
