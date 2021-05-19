#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{

    class Medic : public Player
    {

    public:
        Medic(Board &b, City c) : Player(b, c)
        {
            this->type = "Medic";
        }
        Player &treat(City c) override;
    };
}