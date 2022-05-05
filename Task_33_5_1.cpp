#include <iostream>
#include <map>
#include <string>
#include <exception>
#include <cassert>

std::map <std::string, int> market;
std::map <std::string, int> basket;

void marketFullfillment(std::map <std::string, int> inMap)
{
    std::cout << "What we should place into the market and what amount? " << std::endl;
    std::string position;
    int amount;
    std::cin >> position >> amount;
    if (inMap[position] > 0)
        throw std::exception();
    if (amount <= 0)
        throw std::exception();
    inMap.insert(std::make_pair(position, amount));
}

void basketFullfillment(std::map < std::string, int > inMap, std::map < std::string, int > oMap)
{
    std::cout << "What you want to take?" << std::endl;
    std::string answer;
    std::cin >> answer;
    if (inMap[answer] == 0)
        throw std::exception();
    if (inMap[answer] > 0)
        oMap.insert(std::make_pair(answer, 1));
}

int main()
{
    bool firstRound = true;
    bool secondRound = true;
    while (firstRound)
    {
        std::cout << "Now we're fullfilling a supermarket. If you want to put a thing enter yes, otherwiese no \n";
        std::string answer;
        std::cin >> answer;
        if (answer == "yes")
        {
            try 
            {
                marketFullfillment(market);
            }
            catch (const std::exception &x)
            {
                std::cerr <<"Caught exception" << x.what() << std::endl;
            }
        }
        else if (answer == "no")
            firstRound = false;
        else
            std::cout << "incorrect input, please repeat";
    }
    while (secondRound)
    {
        std::cout << "Now we're fullfilling a basket. If you want to put a thing enter yes, otherwiese no \n";
        std::string answer;
        std::cin >> answer;
        if (answer == "yes")
        {
            try
            {
                basketFullfillment(market, basket);
            }
            catch (const std::exception& y)
            {
                std::cerr <<"Caught exception" << y.what() << std::endl;
            }
        }
        else if (answer == "no")
            secondRound = false;
        else
            std::cout << "incorrect input, please repeat";
    }
}

