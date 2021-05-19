#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player &Medic::treat(City c)
{
   if (this->city != c)
   {
      throw std::invalid_argument{" cant cure unless you are in city " + CitytoString(c)};
   }
   this->board.reduce_diseaseMedicEdition(c);
   return *this;
}
