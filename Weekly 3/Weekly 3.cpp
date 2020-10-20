#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Pvariables.h"


int main()
{
    std::srand(std::time(nullptr));

    std::cout << "Choose difficulty: \n 1 for easy, 2 for medium, 3 for hard, 4 to choose yourself: ";
    std::cin >> difficulty;
    do {
        repeat = false;
        bool repeatc4 = false;
        switch (difficulty) {
        case '1':
            maxnumber = 5;
            break;
        case '2':
            maxnumber = 10;
            break;
        case '3':
            maxnumber = 30;
            break;
        case '4':
            do {
                repeatc4 = false;
                std::cout << "Choose lowest guessabe number: ";
                std::cin >> minnumber;
                std::cout << "Choose highest guessable number: ";
                std::cin >> maxnumber;
                if (minnumber >= maxnumber) {
                    std::cout << "INVALID INPUT, lowest number must be lower than highest number and they cannot be the same, please try again.\n";
                    repeatc4 = true;
                }
            } while (repeatc4);
            break;
        default:
            std::cout << "You did not choose a valid difficulty, please type 1, 2, 3 or 4";
            repeat = true;
        }
    } while (repeat);
    system("cls");


    bool again = false;
    do {
        bool done = false;
        again = false;
        int guesses = 0;
        int gnumber = getRandomNumber(minnumber, maxnumber);

        do {
            guesses++;

            hscore.resize(hscorecounter+1);

            int unumber = 0;

            std::cout << "Guess a number beetween "<<  minnumber << " and " << maxnumber << ": \n";
            std::cin >> unumber;
            if (unumber < gnumber) {
                if (gnumber - unumber < maxnumber / 6) {
                    std::cout << "Very close! Your number was lower than mine. \n";
                }
                else if (gnumber - unumber > maxnumber / 3) {
                    std::cout << "Far off! Your number was lower than mine. \n";
                }
                else {
                    std::cout << "Your number was lower than mine. \n";
                }
            }
            else if (unumber > gnumber) {
                if (unumber - gnumber < maxnumber / 6) {
                    std::cout << "Very close! Your number was higher than mine. \n";
                }
                else if (unumber - gnumber > maxnumber / 3) {
                    std::cout << "Far off! Your number was higher than mine. \n";
                }
                else {
                    std::cout << "Your number was higher than mine. \n";
                }
            }
            else {
                system("cls");
                std::cout << "Your guess was correct! congratulations! you used " << guesses << " guesses.";
                done = true;
                hscore[hscorecounter] = guesses;
                hscorecounter++;
            }
        } while (!done);
        std::cout << "Do you want to try again?(y/n) ";

        char answer = 'n';

        std::cin >> answer;

        if (answer == 'y') {
            again = true;
        }


    } while (again == true);

    std::vector<int> sortingvector(hscore.size());
    for (int i = 0; i < hscore.size(); i++) {
        int lowestnumber = INT_MAX;
        int lastnumber = 0;
        for (int j = 0; j < hscore.size(); j++) {
            if (lowestnumber > hscore.at(j)) {
                lowestnumber = hscore.at(j);
                lastnumber = j;
            }
        }
        sortingvector.at(i) = lowestnumber;
        hscore.at(lastnumber) = INT_MAX;
    }

    std::cout << "high score list: \n";
    for (int i = 0; i < sortingvector.size(); i++) {
        std::cout << sortingvector.at(i) << "\n";
    }
}

