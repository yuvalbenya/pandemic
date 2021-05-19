#pragma once

#include <map>
#include <set>
#include <iostream>

#include "City.hpp"
#include "Color.hpp"
using namespace std;
namespace pandemic
{

    class Board
    {

    protected:
        map<City, int> cubes;
        static std::map<City, std::set<City>> connections;
        set<Color> isCured;
        static map<City, Color> cities_colors;
        set<City> researched;

        //    static map<Color, bool> isCured = {{Red, false}, {Black, false}, {Blue, false}, {Yellow, false}};

    public:
        Board();

        void reduce_disease(City c);
        int &operator[](City c);
        bool is_clean();
        static bool is_connected(const City &c1, const City &c2);
        void build_research_station(City c);
        bool is_research_station(City c);
        void add_cure(Color c);
        bool check_cure(Color c);
        bool is_cure_discoverd(City c);
        // Color color_of(City c);
        friend std::ostream &operator<<(std::ostream &out, Board &b);
        void reduce_diseaseMedicEdition(City c);
        void reduce_diseaseVirologistEdition(City c);
        void remove_cures();
        void reduce_diseaseFieldDoctorEdition(City c);
        static Color getCityColor(City c);
        void remove_stations();
    };
}
