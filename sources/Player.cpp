#include "Player.hpp"
#include <iostream>
#include <set>
#include <sstream> 
#include <string> 

namespace pandemic{

    Player& Player::take_card(City city){
        this->cards.insert(city);
        return *this;
    }
    Player& Player::drive(City city){
        if (this->city == city)
            {throw std::invalid_argument{"You are alredy in" + board.toString[city]};}

        if (this->board.connectionsMap[this->city].find(city) != this->board.connectionsMap[this->city].end()){
            {this->city = city;
             if (this->p_role == "Medic" && board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
            }
        }
        else
        {throw std::invalid_argument{"illegal action: " + board.toString[this->city] + " is not connected to " + board.toString[city]};}
            
            return *this;
    }
    
    Player& Player::fly_charter(City city){
        if (this->city != city){
        if(this->cards.find(this->city) != this->cards.end())
            {cards.erase(this->city);
             this->city = city;
        
        if (this->p_role == "Medic" && board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
            }
        else
            {throw std::logic_error{ "illegal action: you do not have the " + board.toString[this->city] + " card (the card of the city you are in)."};}
        }
        else 
        {throw std::logic_error{ "illegal action: can not fly from a city to itself"};}
        return *this;
    }
    Player& Player::fly_shuttle(City city){
       if (this->city != city){
        if (board.researchStationsSet.find(this->city) == board.researchStationsSet.end())
            {throw std::logic_error{ "illegal action: there is no research station in " + board.toString[this->city] +"."};}
        if (board.researchStationsSet.find(city) != board.researchStationsSet.end())
            {this->city = city;
             if (this->p_role == "Medic" && board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
               }
        else 
            {throw std::logic_error{ "illegal action: there is no research station in " + board.toString[this->city] +"."};}
       }
       else 
        {throw std::logic_error{ "illegal action: can not fly from a city to itself"};} 
        return *this;
    }
    Player& Player::fly_direct(City city){
    if (this->city != city){
        if (this->cards.find(city)!= this->cards.end())
            {this->city = city;
             cards.erase(city);
             if (this->p_role == "Medic" && board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
               }
        else
             {throw std::invalid_argument{" illegal action: you do not have the card of " + board.toString[city]};}
        }
    else
    {throw std::logic_error{ "illegal action: can not fly from a city to itself"};}
        return *this;
    };
    Player& Player::build(){
        if (this->cards.find(this->city) != this->cards.end())
            {auto result = this->board.researchStationsSet.insert(this->city);
             if (result.second)
                {this->cards.erase(this->city);}} 
        else 
            {throw std::logic_error{"illegal action: you do not have the card of " + board.toString[city]};}
        return *this;
    }
    Player& Player::treat(City city){

        if (this->city != city)
            {throw std::logic_error{"illegal action: you are not in " + board.toString[city]};}

        if (this->board.diseaseCubes[city] > 0)
            { if (board.discovered_cures.find(board.colorMap[city]) != board.discovered_cures.end())
               {board.diseaseCubes[city] = 0;}
              else
               {this->board.diseaseCubes[city] -= 1;} 
            }
        else 
            {throw std::logic_error{"illegal action: no more cubes remain in " + board.toString[city]};}
        return *this;
    }
    Player& Player::discover_cure(Color color){ 
    if (board.researchStationsSet.find(this->city) != board.researchStationsSet.end())
    {
    std::string color_string = ToString(color);
    std::set<City> matched_color_cards; 
    
    for (const auto& iter: cards){
        if (board.colorMap.at(iter) == color)
            {matched_color_cards.insert(iter);}
      }
    
    if (matched_color_cards.size() >= no_of_cards_to_discover_cure)
        {
        for (const auto& iter: matched_color_cards){
            cards.erase(iter);
        }
        board.discovered_cures.insert(color);
        }

    else 
        { std::ostringstream ostr;
            ostr << "illegal action: you only have " << matched_color_cards.size() << " " << color_string << " cards remaining.";
            std::string error_string = ostr.str();
            throw std::logic_error{error_string};
        }
    }
    else
      {throw std::logic_error{ "illegal action: there is no research station in " + board.toString[this->city] +"."};}
return *this;
 }
} 