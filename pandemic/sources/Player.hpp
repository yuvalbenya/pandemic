#pragma once
#include <iostream>
#include <set>
#include <vector>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic
{

    class Player
    {
    protected:
        std::set<City> cards;
        Board &board;
        City city;
        std::string type;

    public:
        Player(Board &b, City c) : board(b), city(c), type("player") {}

        virtual Player &take_card(City c);
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        virtual std::string role();
    };
}
