#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{

   if (!Board::is_connected(this->city, c) && city != c)
   {
      throw std::invalid_argument{" you do not possess 5 cards of the desired color "};
   }
   this->board.reduce_diseaseFieldDoctorEdition(c);
   return *this;
}