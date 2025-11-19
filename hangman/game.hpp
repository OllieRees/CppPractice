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
        void add_guess(char c) { this->correct_letters_guessed.insert(c); }
        bool has_guessed_word() { return this -> word->get_characters() == this -> correct_letters_guessed; }
        int get_wrong_guesses_count() const { return wrong_guesses_count; }
    private:
        std::set<char> correct_letters_guessed = std::set<char>();
        int wrong_guesses_count = 0;
        Word* word;
};