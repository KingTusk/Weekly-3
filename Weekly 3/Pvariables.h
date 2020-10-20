#pragma once
#include <vector>


std::vector<int> hscore = { 0 };
int hscorecounter = 0;
int maxnumber = 5;
int minnumber = 1;
char difficulty = 1;
bool repeat = false;

int getRandomNumber(int min, int max) //code in this function is from https://www.learncpp.com/cpp-tutorial/59-random-number-generation/
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}