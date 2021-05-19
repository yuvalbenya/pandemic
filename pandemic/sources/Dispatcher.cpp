#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    if (this->city == c)
    {
        throw std::invalid_argument{" try to fly from City to itself "};
    }
    if (this->board.is_research_station(this->city))
    {
        this->city = c;
        return *this;
    }
    return Player::fly_direct(c);
}