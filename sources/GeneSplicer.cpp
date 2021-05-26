#include "GeneSplicer.hpp"
#include <sstream>


namespace pandemic{
    Player& GeneSplicer::discover_cure(Color color){
    if (board.researchStationsSet.find(this->city) != board.researchStationsSet.end())
    {
    std::string color_string = ToString(color);
    std::cout << cards.size();
    if (cards.size() >= no_of_cards_to_discover_cure)
        {
        auto iter = cards.begin(); 
        for (int i=0; i<no_of_cards_to_discover_cure; i++){
            iter = cards.erase(iter);
        }
        board.discovered_cures.insert(color);    
        }

    else 
        { std::ostringstream ostr;
            ostr << "illegal action: you only have " << cards.size() << " " << color_string << " cards remaining.";
            std::string error_string = ostr.str();
            throw std::logic_error{error_string};
        }
    }
    else
        {throw std::logic_error{ "illegal action: there is no research station in " + board.toString[this->city] +"."};}
    return *this;
}
}