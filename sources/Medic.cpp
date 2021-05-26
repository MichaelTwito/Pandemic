#include "Medic.hpp"

namespace pandemic{

    Player& Medic::treat(City city){
        if (this->city != city)
            {throw std::logic_error{"illegal action: you are not in " + board.toString[city]};}

        if (this->board.diseaseCubes[city] > 0)
            {this->board.diseaseCubes[city] = 0;}
        else 
            {throw std::logic_error{"illegal action: no more cubes remain in " + board.toString[city]};}
        
        return *this;
    }
}