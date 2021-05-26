#include "Player.hpp"

namespace pandemic{
    class Scientist: public Player{
        private:
        int no_of_cards_to_discover_cure;
        public:
        Scientist(Board &board, City city, int no_of_cards_to_discover_cure):no_of_cards_to_discover_cure(no_of_cards_to_discover_cure), Player(board, "Scientist", city){};
        Player& discover_cure(Color color) override;
    };
}