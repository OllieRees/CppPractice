#include "include/display.hpp"
#include <iostream>

Console::Console(Game* game) 
    : Display(game), drawer(new DefaultConsoleHangmanDrawer()), owns_drawer(true) {}

Console::Console(Game* game, ConsoleHangmanDrawer* drawer) 
    : Display(game), drawer(drawer), owns_drawer(false) {}

Console::~Console() {
    if (owns_drawer) {
        delete drawer;
    }
}

void Console::display_word() {
    auto word = this->get_game()->get_word();
    for(char c : word->get_word()) {
        if (this->get_game()->has_guessed_character(c)) {
            std::cout << c << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

void Console::display_hangman() {
    if (this->drawer != nullptr && this->get_game() != nullptr) {
        this->drawer->draw(this->get_game()->get_wrong_guesses());
    }
}