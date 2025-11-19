#include "game.hpp"

void Game::guess_letter(char c) {
    if (state->is_successful_guess(c)) {
        state->add_correct_guess(c);
    } else {
        state->increment_wrong_guesses_count();
    }
}