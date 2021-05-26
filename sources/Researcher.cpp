#include "Researcher.hpp"
#include <sstream>

namespace pandemic{
    Player& Researcher::discover_cure(Color color){
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
    return *this;
}
}