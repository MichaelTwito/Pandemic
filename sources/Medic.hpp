#include "Player.hpp"

namespace pandemic{
    class Medic: public Player{
        public:
        Medic(Board &board, City city): Player(board, "Medic", city){}
        Player& treat(City city);

    };
}