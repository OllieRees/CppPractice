#include "include/display.hpp"
#include <iostream>

int main(int, char**) {
    WordGeneratorAPI* word_generator = new WordGeneratorAPI(new WordGeneratorRandomWordClient());
    Game* game = new Game(word_generator->generate_word(), 6);
    Display* display = new Console(game);
    std::cout << display->get_game()->get_word()->get_word() << std::endl;
    display -> display_word();
}
