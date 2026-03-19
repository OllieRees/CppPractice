#include "include/game.hpp"
#include <set>

State Game::make_guess(char c) {
    guesses.push_back(c);
    if (!(this -> word -> contains_character(c))) {
        wrong_guesses++; 
    }
    if (this->has_won()) { return State::win; }
    if (this->has_lost()) { return State::lose; }
    return State::in_progress;
}

bool Game::has_lost() const {
    return wrong_guesses >= settings -> get_max_lives(); 
}

bool Game::has_won() const {
    // TODO: Improve performance so we can utilise set operations (subset/intersection)
    const auto& word_chars = this->word->get_characters();
    return std::all_of(word_chars.begin(), word_chars.end(), [&](char c) {
        return std::find(this->guesses.begin(), this->guesses.end(), c) != this->guesses.end();
    });
}

bool Game::has_guessed_character(char c) {
    return std::find(this->guesses.begin(), this->guesses.end(), c) != this->guesses.end();
}