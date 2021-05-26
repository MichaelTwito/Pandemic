#include "Dispatcher.hpp"

namespace pandemic{
     Player& Dispatcher::fly_direct(City city){
      if (this->city != city){
        if (board.researchStationsSet.find(this->city) != board.researchStationsSet.end())
            {this->city = city;}
        else{ 
        if(this->cards.find(city)!= this->cards.end())
             {this->city = city;
             cards.erase(city);
             }    
        else
          {throw std::invalid_argument{" illegal action: you do not have the card of " + board.toString[city]};}
        }
      }
      else
      {throw std::logic_error{ "illegal action: can not fly from a city to itself"};}
        return *this;
    };
}