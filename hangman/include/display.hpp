#pragma once

#include "game.hpp"
#include "drawer.hpp"

class Display {
    public:
        Display(Game* game): game(game) {}
        virtual ~Display() = default;
        virtual void display_word() = 0;
        virtual void display_hangman() = 0;
        virtual void displayHangman() { display_hangman(); }
        Game* get_game() const { return game; }
        int get_max_lives() const { return game != nullptr ? game->get_max_lives() : 0; }
    private:
        Game* game;
};

class Console: public Display {
    public:
        Console(Game* game);
        Console(Game* game, ConsoleHangmanDrawer* drawer);
        ~Console() override;
        void display_word() override;
        void display_hangman() override;
        void displayHangman() override { display_hangman(); }
        void drawHangman() { display_hangman(); }
        ConsoleHangmanDrawer* get_drawer() const { return drawer; }
    private:
        ConsoleHangmanDrawer* drawer;
        bool owns_drawer;
};