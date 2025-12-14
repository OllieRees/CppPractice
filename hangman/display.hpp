#include "game.hpp"

class Display {
    public:
        Display(Game* game): game(game) {}
        virtual void display_word() = 0;
        Game* get_game() const { return game; }
    private:
        Game* game;
};

class Console: public Display {
    public:
        Console(Game* game): Display(game) {}
        void display_word();
};