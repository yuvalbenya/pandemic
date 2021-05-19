#pragma once

#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int n;

    public:
        Scientist(Board &b, City c, int number) : Player(b, c), n(number)
        {
            this->type = "Scientist";
        }
        Scientist &discover_cure(Color c) override;
        vector<City> getColors(Color color);
    };
}