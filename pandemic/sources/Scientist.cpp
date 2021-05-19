#include "Scientist.hpp"
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;
using namespace pandemic;

Scientist &Scientist::discover_cure(Color c)
{
    if (this->board.check_cure(c))
    {
        return *this;
    }

    if (this->board.is_research_station(this->city))
    {
        vector<City> vc = getColors(c);
        int count = vc.size();
        if (count >= this->n)
        {
            for (size_t i = 0; i < this->n; i++)
            {
                cards.erase(vc.at(i));
            }
            board.add_cure(c);
        }
        else
        {
            throw std::invalid_argument{" you do not possess 5 cards of the desired color "};
        }
    }
    else
    {
        throw std::invalid_argument{" current city does not have a research center"};
    }
    return *this;
}

vector<City> Scientist::getColors(Color color)
{
    vector<City> vc;
    for (const auto &x : this->cards)
    {
        if (Board::getCityColor(x) == color)
        {
            vc.push_back(x);
        }
    }
    return vc;
}
