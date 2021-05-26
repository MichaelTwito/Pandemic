#include "OperationsExpert.hpp"
#include <iostream>

namespace pandemic{
    Player& OperationsExpert::build(){
        board.researchStationsSet.insert(this->city);
        return *this;
    }
}