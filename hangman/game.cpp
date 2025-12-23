#include "game.hpp"
#include <set>

void Game::make_guess(char c) {
    if (this -> has_lost()) {
        throw std::runtime_error("Can't make a guess when you've lost");
    }

    guesses.push_back(c);
    if (!(this -> word -> contains_character(c))) {
        wrong_guesses++;
    };
}

bool Game::has_won() const {    
    return std::includes(
        this->guesses.begin(), this->guesses.end(), 
        this->word->get_word().begin(), this->word->get_word().end()
    );
}