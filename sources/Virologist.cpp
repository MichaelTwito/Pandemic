#include "Virologist.hpp"

namespace pandemic{
    Player& Virologist::treat(City city){
        if (this->city == city)
         {if (this->board.diseaseCubes[city] > 0)
            { if (board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
              else
               {this->board.diseaseCubes[city] -= 1;} 
            }
          else 
                {throw std::logic_error{"illegal action: no more cubes remain in " + board.toString[city]};}}
        else{
        if (this->cards.find(city) == this->cards.end())
            {throw std::logic_error{"illegal action: you don't have the " + board.toString[city] + " card."};}

        if (this->board.diseaseCubes[city] > 0)
            { if (board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
              else
               {this->board.diseaseCubes[city] -= 1;} 
            this->cards.erase(city);
            }
        else 
            {throw std::logic_error{"illegal action: no more cubes remain in " + board.toString[city]};}}
        return *this;
    }
}