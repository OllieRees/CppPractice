#include "include/display.hpp"
#include <iostream>
#include <format>
#include <stdexcept>

Console::Console(Game* game) 
    : Display(game), drawer(new DefaultConsoleHangmanDrawer()), owns_drawer(true) {
        if (game == nullptr) {
            throw std::invalid_argument("Console Display must require a valid Game");
        }
        if (drawer->get_max_allowed_lives() < game->get_max_lives()) {
            delete drawer;
            drawer = nullptr;
            throw std::invalid_argument(
                std::format(
                    "Game's max lives is {}, whilst the hangman's allowed max lives is {}",
                    game->get_max_lives(), 6
                )
            );
        }
    }

Console::Console(Game* game, ConsoleHangmanDrawer* drawer) 
    : Display(game), drawer(drawer), owns_drawer(false) {
        if (game == nullptr) {
            throw std::invalid_argument("Console Display must require a valid Game");
        }
        if (drawer == nullptr) {
            throw std::invalid_argument("Console Display must require a valid Drawing Strategy");
        }
        if (drawer->get_max_allowed_lives() < game->get_max_lives()) {
            throw std::invalid_argument(
                std::format(
                    "Game's max lives is {}, whilst the hangman's allowed max lives is {}",
                    game->get_max_lives(), drawer->get_max_allowed_lives()
                )
            );
        }
    }

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