#include "Scientist.hpp"
#include <sstream>

namespace pandemic{
    Player& Scientist::discover_cure(Color color){
    if (board.researchStationsSet.find(this->city) != board.researchStationsSet.end())
       {
        std::string color_string = ToString(color);
        std::set<City> matched_color_cards; 
    
        int no_of_cards_to_discover_cure = this->no_of_cards_to_discover_cure; 

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