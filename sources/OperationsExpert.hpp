#pragma once
#include "Player.hpp"


namespace pandemic{

class OperationsExpert: public Player{
    public:
    
    OperationsExpert(Board &board, City city): Player(board, "OperationsExpert", city){};
    Player& build() override;
};
}