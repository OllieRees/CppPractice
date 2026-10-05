#include "include/display.hpp"
#include "include/input.hpp"
#include <iostream>

int main(int, char**) {
    WordGeneratorAPI* word_generator = new WordGeneratorAPI(new WordGeneratorRandomWordWithMetadataClient());
    Game* game = new Game(word_generator->generate_word(), 6);
    Display* display = new Console(game);
    Inputter* inputter = new ConsoleInputter();

    State state = State::in_progress;
    while (state == State::in_progress) {
        display->display_word();
        char guess = inputter->input_letter();
        state = game->make_guess(guess);
    }

    display->display_word();
    if (state == State::win) {
        std::cout << "Congratulations! You won!\n";
    } else {
        std::cout << "Game Over! The word was: " << game->get_word()->get_word() << "\n";
    }

    delete inputter;
    delete display;
    delete game;
    delete word_generator;
    return 0;
}
