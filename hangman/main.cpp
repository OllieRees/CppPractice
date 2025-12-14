#include "display.hpp"
#include <iostream>

int main(int, char**) {
    Game* game = new Game((new WordGeneratorAPI())->generate_word(), 6);
    Display* display = new Console(game);
    std::cout << display->get_game()->get_word()->get_word() << std::endl;
    display -> display_word();
}
