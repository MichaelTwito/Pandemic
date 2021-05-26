#pragma once

#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <iostream>
#include <map>
#include <set>

namespace pandemic{

class Board{
    public:
        
        Board();

        std::map<City, std::set<City>> connectionsMap;
        
        std::map<City, int> diseaseCubes;
        
        std::map<City, Color> colorMap;
        
        std::set<City> researchStationsSet;

        std::set<Color> discovered_cures;

        std::map<City, std::string> toString =  {{Algiers, "Algiers"},{City::Atlanta, "Atlanta"},{City::Baghdad, "Baghdad"},{City::Bangkok, "Bangkok"}, 
        {City::Beijing, "Beijing"},{City::Bogota, "Bogota"},{City::BuenosAires, "BuenosAires"},
        {City::Cairo, "Cairo"},{City::Chennai, "Chennai"},{City::Chicago, "Chicago"},{City::Delhi, "Delhi"},
        {City::Essen, "Essen"},{City::HoChiMinhCity, "HoChiMinhCity"},{City::HongKong, "HongKong"},
        {City::Istanbul, "Istanbul"},{City::Jakarta, "Jakarta"},{City::Johannesburg, "Johannesburg"},
        {City::Karachi, "Karachi"},{City::Khartoum, "Khartoum"},{City::Kinshasa, "Kinshasa"},
        {City::Kolkata, "Kolkata"},{City::Lagos,"Lagos"},{City::Lima,"Lima" },{City::London,"London"},
        {City::LosAngeles,"LosAngeles"}, {City::Madrid,"Madrid"},{City::Manila,"Manila"},{City::MexicoCity,"MexicoCity"},
        {City::Miami,"Miami"},{City::Milan, "Milan"},{City::Montreal,"Montreal"},{City::Moscow, "Moscow"},
        {City::Mumbai,"Mumbai"},{City::NewYork,"NewYork"},{City::Osaka,"Osaka"},{City::Paris,"Paris"},
        {City::Riyadh, "Riyadh"},{City::SanFrancisco,"SanFrancisco"},{City::Santiago, "Santiago"}, {City::SaoPaulo,"SaoPaulo"},
        {City::Seoul,"Seoul"},{City::Shanghai,"Shanghai"},{City::StPetersburg,"StPetersburg"}, {City::Sydney,"Sydney"},
        {City::Taipei, "Taipei"},{City::Tehran,"Tehran"},{City::Tokyo,"Tokyo" },{City::Washington,"Washington" }};
        
        int& operator[](City city);
        bool is_clean();
        void remove_cures();
        void remove_stations();
        friend std::ostream& operator<<(std::ostream &os, const Board &b);
    };
}