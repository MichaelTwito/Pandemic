#include "Player.hpp"

namespace pandemic{
class Virologist: public Player{
public:
Virologist(Board &board, City city): Player(board, "Virologist", city){};
Player& treat(City city);
};
}