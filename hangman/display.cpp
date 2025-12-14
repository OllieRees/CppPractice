#include "display.hpp"
#include "iostream"

void Console::display_word() {
    auto word = this->get_game()->get_word();
    for(char c : word->get_word()) {
        std::cout << "_ ";
    }
    std::cout << std::endl;
}