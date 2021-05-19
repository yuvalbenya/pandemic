#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        OperationsExpert(Board &b, City c) : Player(b, c)
        {
            this->type = "OperationsExpert";
        }
        Player &build() override;
    };
}