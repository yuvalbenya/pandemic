#include "Player.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;
using namespace pandemic;

const int FIVE = 5;

Player &Player::drive(const City c)
{
    if (this->city == c)
    {
        throw std::invalid_argument{"the player is already in that city" + CitytoString(this->city)};
    }
    if (Board::is_connected(this->city, c))
    {
        this->city = c;
        if (this->type == "Medic" && this->board.check_cure(Board::getCityColor(c)))
        {
            this->board[c] = 0;
        }
        return *this;
    }
    throw std::invalid_argument{CitytoString(c) + " is not connected to " + CitytoString(this->city)};
}
Player &Player::fly_direct(const City c)
{
    if (this->city == c)
    {
        throw std::invalid_argument{"the player is already in that city" + CitytoString(this->city)};
    }
    if (this->cards.count(c) > 0)
    {
        this->cards.erase(c);
        this->city = c;
        if (this->type == "Medic" && this->board.check_cure(Board::getCityColor(c)))
        {
            this->board[c] = 0;
        }
        return *this;
    }
    throw std::invalid_argument{" the player does not hold the following: " + CitytoString(c)};
}

Player &Player::fly_charter(const City c)
{
    if (this->city == c)
    {
        throw std::invalid_argument{"the player is already in that city" + CitytoString(this->city)};
    }
    if (this->cards.count(this->city) > 0)
    {
        this->cards.erase(this->city);
        this->city = c;
        if (this->type == "Medic" && this->board.check_cure(Board::getCityColor(c)))
        {
            this->board[c] = 0;
        }
        return *this;
    }
    throw std::invalid_argument{" the player does not hold the following card: " + CitytoString(this->city)};
}

Player &Player::fly_shuttle(const City c)
{
    if (this->city == c)
    {
        throw std::invalid_argument{"the player is already in that city" + CitytoString(this->city)};
    }
    if (this->board.is_research_station(this->city))
    {
        if (this->board.is_research_station(c))
        {
            this->city = c;
            if (this->type == "Medic" && this->board.check_cure(Board::getCityColor(c)))
            {
                this->board[c] = 0;
            }
            return *this;
        }
        throw std::invalid_argument{" the following city does not have a research station: " + CitytoString(c)};
    }
    throw std::invalid_argument{" the following city does not have a research station: " + CitytoString(this->city)};
    return *this;
}
Player &Player::build()
{
    if (cards.count(city) == 0)
    {
        throw std::invalid_argument{" the player does not hold the following card: " + CitytoString(city)};
    }
    if (board.is_research_station(city))
    {
        return *this;
    }
    cards.erase(city);
    board.build_research_station(city);
    return *this;
}
Player &Player::discover_cure(Color c)
{
    if (this->board.is_research_station(this->city))
    {
        if (this->board.check_cure(c))
        {
            return *this;
        }
        int count = 0;
        for (auto it = this->cards.begin(); it != this->cards.end(); it++)
        {
            if (Board::getCityColor(*it) == c)
            {
                count++;
            }
        }
        if (count < FIVE)
        {
            throw std::invalid_argument{" you do not possess 5 cards of the desired color "};
        }

        vector<City> vc;
        for (auto it = this->cards.begin(); it != this->cards.end(); it++)
        {

            if (Board::getCityColor(*it) == c)
            {
                vc.push_back(*it);
            }
        }
        for (size_t i = 0; i < FIVE; i++)
        {
            cards.erase(vc.at(i));
        }
        board.add_cure(c);
        return *this;
    }
    throw std::invalid_argument{" current city does not have a research center"};
}

Player &Player::treat(City c)
{
    if (this->city != c)
    {
        throw std::invalid_argument{" cant cure unless you are in city " + CitytoString(c)};
    }
    this->board.reduce_disease(c);
    this->cards.erase(c);
    return *this;
}

Player &Player::take_card(City c)
{
    this->cards.insert(c);
    return *this;
}

string Player::role()
{
    return this->type;
}
