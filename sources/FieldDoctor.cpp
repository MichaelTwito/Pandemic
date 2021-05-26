#include "FieldDoctor.hpp"

namespace pandemic{
Player& FieldDoctor::treat(City city){
    if (this->city == city)
        {if (this->board.diseaseCubes[city] > 0)
            {if (board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
             else
               {this->board.diseaseCubes[city] -= 1;} 
            }
         else 
        {throw std::logic_error{"illegal action: no more cubes remain in " + board.toString[city]};}}
    else{
        if (board.connectionsMap[this->city].find(city) == board.connectionsMap[this->city].end())
            {throw std::logic_error{"illegal action: you are not in " + board.toString[city] + " or any neighbour city."};}

        if (this->board.diseaseCubes[city] > 0)
            { if (board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
              else
               {this->board.diseaseCubes[city] -= 1;} 
            }
        else 
            {throw std::logic_error{"illegal action: no more cubes remain in " + board.toString[city]};}}
        return *this;
}
}