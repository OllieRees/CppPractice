#include "include/display.hpp"
#include "iostream"

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