#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;
const int FIVE = 5;
Player &GeneSplicer::discover_cure(Color c)
{
        if (this->board.is_research_station(this->city))
        {
                size_t size = cards.size();
                if (size < FIVE)
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
                        vc.push_back(*it);
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