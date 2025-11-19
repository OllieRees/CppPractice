#include <set>
#include "word.hpp"


class Config {
    public:
        Config(int lives_count) : lives_count(lives_count) {}
    private:
        const int lives_count;
};


class Game {
    public:
        Game(Word* word, Config* config): state(new State(word)), config(config) {}
        void guess_letter(char c);
    private:
        State* state;
        Config* config;
};


class State {
    public: 
        State(Word* word) : word(word) {}
        bool has_guessed_word() const { return word->get_characters() == correct_letters_guessed; }
        bool is_successful_guess(char c) const { return word->contains_character(c); }
        int get_wrong_guesses_count() const { return wrong_guesses_count; }
        void increment_wrong_guesses_count() { wrong_guesses_count++; }
        void add_correct_guess(char c) { correct_letters_guessed.insert(c); } 
    private:
        std::set<char> correct_letters_guessed = std::set<char>();
        int wrong_guesses_count = 0;
        Word* word;
};