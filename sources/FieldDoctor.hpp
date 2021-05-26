#include "Player.hpp"
namespace pandemic{

class FieldDoctor: public Player{
    public:
    
    FieldDoctor(Board &board, City city): Player(board, "FieldDoctor",city){}
    Player& treat(City city) override;
};

}