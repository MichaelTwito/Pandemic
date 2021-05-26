
#include "Player.hpp"

namespace pandemic{
    class Researcher: public Player{
        public:
        Researcher(Board &board, City city): Player(board, "Researcher", city){};
        Player& discover_cure(Color color) override;
    };
}