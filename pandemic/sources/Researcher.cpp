#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

const int FIVE = 5;
Player &Researcher::discover_cure(Color c)
{
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
    if (this->board.check_cure(c))
    {
        return *this;
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