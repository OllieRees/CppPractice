#include "game.hpp"
#include <iostream>

int main(int, char**) {
    WordGenerator* generator = new WordGeneratorAPI();
    Game* game = new Game(generator->generate_word(), 6);
    std::cout << game->get_word()->get_word() << std::endl;
}
