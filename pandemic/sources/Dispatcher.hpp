#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{

    class Dispatcher : public Player
    {

    public:
        Dispatcher(Board &board, City city) : Player(board, city)
        {
            this->type = "Dispatcher";
        }

        // Dispatcher(Board& b, City c): Player(b, c, "Dispatcher"){}
        Player &fly_direct(City c) override;
    };
}