#pragma once
#include "Board.hpp"
#include "City.hpp"


namespace pandemic{

static const int no_of_cards_to_discover_cure = 5;

    class Player{ 
        protected:

        Board& board;
        std::string p_role;
        std::set<City> cards;
        City city;
        
        public:
        
        Player(Board& board, std::string p_role, City city): board(board),  p_role(p_role), city(city){};
        
        const std::string role(){return p_role;};
        
        Player& take_card(City city);
        Player& drive(City city);
        
        Player& fly_charter(City city);
        Player& fly_shuttle(City city);
        virtual Player& fly_direct(City city);
        virtual Player& build();
        virtual Player& treat(City city);
        virtual Player& discover_cure(Color color);
    };
}