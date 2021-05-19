#include <algorithm>
#include <iostream>

#include "Board.hpp"
#include "City.hpp"
using namespace std;
using namespace pandemic;

Board::Board()
{
    for (int c = (int)City::Algiers; c <= (int)City::Washington; c++)
    {
        cubes[(City)c] = 0;
    }
    researched.clear();
    isCured.clear();
}

int &Board::operator[](City c)
{
    return cubes[c];
}
std::ostream &pandemic::operator<<(std::ostream &out, Board &b) { return out; }
bool Board::is_clean()
{
    for (pair<City, int> p : this->cubes)
    {
        if (p.second > 0)
        {
            return false;
        }
    }
    return true;
}
bool Board::is_connected(const City &c1, const City &c2)
{

    return connections.at(c1).count(c2) > 0;
}
bool Board::is_research_station(City c)
{
    return (researched.count(c) != 0);
}
void Board::build_research_station(City c)
{
    researched.insert(c);
}

bool Board::check_cure(Color c)
{
    return (isCured.count(c) != 0);
}
void Board::add_cure(Color c)
{
    this->isCured.insert(c);
}
void Board::reduce_disease(City c)
{
    if (this->cubes.at(c) > 0)
    {
        if (this->isCured.count(cities_colors.at(c)) != 0)
        {
            this->cubes.at(c) = 0;
        }
        else
        {
            this->cubes.at(c)--;
        }
        return;
    }
    throw std::invalid_argument{" the desired city disease level is 0 "};
}
void Board::reduce_diseaseMedicEdition(City c)
{
    if (this->cubes.at(c) > 0)
    {
        this->cubes.at(c) = 0;
        return;
    }
    throw std::invalid_argument{" the desired city disease level is 0 "};
}
void Board::reduce_diseaseVirologistEdition(City c)
{
    if (this->cubes.at(c) > 0)
    {
        if (this->isCured.count(cities_colors.at(c)) != 0)
        {
            this->cubes.at(c) = 0;
        }
        else
        {
            this->cubes.at(c)--;
        }
        return;
    }
    throw std::invalid_argument{" the desired city disease level is 0 "};
}
void Board::remove_cures()
{
    isCured.clear();
}
void Board::reduce_diseaseFieldDoctorEdition(City c)
{
    if (this->cubes.at(c) > 0)
    {
        if (this->isCured.count(cities_colors.at(c)) != 0)
        {
            this->cubes.at(c) = 0;
        }
        else
        {
            this->cubes.at(c)--;
        }
        return;
    }
    throw std::invalid_argument{" the desired city disease level is 0 "};
}
Color Board::getCityColor(City c)
{
    return cities_colors.at(c);
}
void Board::remove_stations()
{
    researched.clear();
}

std::map<City, std::set<City>> Board::connections{
    {Algiers, {Madrid, Paris, Istanbul, Cairo}},
    {Atlanta, {Chicago, Miami, Washington}},
    {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
    {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
    {Beijing, {Shanghai, Seoul}},
    {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
    {BuenosAires, {Bogota, SaoPaulo}},
    {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
    {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
    {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
    {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
    {Essen, {London, Paris, Milan, StPetersburg}},
    {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
    {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
    {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
    {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
    {Johannesburg, {Kinshasa, Khartoum}},
    {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
    {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
    {Kinshasa, {Lagos, Khartoum, Johannesburg}},
    {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
    {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
    {Lima, {MexicoCity, Bogota, Santiago}},
    {London, {NewYork, Madrid, Essen, Paris}},
    {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
    {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
    {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
    {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
    {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
    {Milan, {Essen, Paris, Istanbul}},
    {Montreal, {Chicago, Washington, NewYork}},
    {Moscow, {StPetersburg, Istanbul, Tehran}},
    {Mumbai, {Karachi, Delhi, Chennai}},
    {NewYork, {Montreal, Washington, London, Madrid}},
    {Osaka, {Taipei, Tokyo}},
    {Paris, {Algiers, Essen, Madrid, Milan, London}},
    {Riyadh, {Baghdad, Cairo, Karachi}},
    {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
    {Santiago, {Lima}},
    {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
    {Seoul, {Beijing, Shanghai, Tokyo}},
    {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
    {StPetersburg, {Essen, Istanbul, Moscow}},
    {Sydney, {Jakarta, Manila, LosAngeles}},
    {Taipei, {Shanghai, HongKong, Osaka, Manila}},
    {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
    {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
    {Washington, {Atlanta, NewYork, Montreal, Miami}}};

std::map<City, Color> Board::cities_colors{
    {City::Algiers, Color::Black},
    {City::Atlanta, Color::Blue},
    {City::Baghdad, Color::Black},
    {City::Bangkok, Color::Red},
    {City::Beijing, Color::Red},
    {City::Bogota, Color::Yellow},
    {City::BuenosAires, Color::Yellow},
    {City::Cairo, Color::Black},
    {City::Chennai, Color::Black},
    {City::Chicago, Color::Blue},
    {City::Delhi, Color::Black},
    {City::Essen, Color::Blue},
    {City::HoChiMinhCity, Color::Red},
    {City::HongKong, Color::Red},
    {City::Istanbul, Color::Black},
    {City::Jakarta, Color::Red},
    {City::Johannesburg, Color::Yellow},
    {City::Karachi, Color::Black},
    {City::Khartoum, Color::Yellow},
    {City::Kinshasa, Color::Yellow},
    {City::Kolkata, Color::Black},
    {City::Lagos, Color::Yellow},
    {City::Lima, Color::Yellow},
    {City::London, Color::Blue},
    {City::LosAngeles, Color::Yellow},
    {City::Madrid, Color::Blue},
    {City::Manila, Color::Red},
    {City::MexicoCity, Color::Yellow},
    {City::Miami, Color::Yellow},
    {City::Milan, Color::Blue},
    {City::Montreal, Color::Blue},
    {City::Moscow, Color::Black},
    {City::Mumbai, Color::Black},
    {City::NewYork, Color::Blue},
    {City::Osaka, Color::Red},
    {City::Paris, Color::Blue},
    {City::Riyadh, Color::Black},
    {City::SanFrancisco, Color::Blue},
    {City::Santiago, Color::Yellow},
    {City::SaoPaulo, Color::Yellow},
    {City::Seoul, Color::Red},
    {City::Shanghai, Color::Red},
    {City::StPetersburg, Color::Blue},
    {City::Sydney, Color::Red},
    {City::Taipei, Color::Red},
    {City::Tehran, Color::Black},
    {City::Tokyo, Color::Red},
    {City::Washington, Color::Blue}};

// bool Board::is_connected(const City& c1,const City& c2){return true;}

// void Board::build_research_station(const City c){}

// bool Board::is_research_station(const City c){return true;}

// void Board::discover_cure(const City c){}

// Color Board::color_of(City c){return Red;}
