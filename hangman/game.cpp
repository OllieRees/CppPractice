#include "game.hpp"
#include <set>

State Game::make_guess(char c) {
    if (this->has_lost()) { return State::lose; }
    guesses.push_back(c);
    if (this->has_won()) { return State::win; }
    if (!(this -> word -> contains_character(c))) {
        wrong_guesses++;
    };
    return State::in_progress;
}

bool Game::has_won() const {    
    return std::includes(
        this->guesses.begin(), this->guesses.end(), 
        this->word->get_word().begin(), this->word->get_word().end()
    );
}