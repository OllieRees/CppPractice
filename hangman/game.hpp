#include <vector>
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
    private:
        State* state;
        Config* config;
};


class State {
    public: 
        State(Word* word) : word(word) {}
        void guess_letter(char c);
    private:
        std::vector<char> correct_letters_guessed = std::vector<char>();
        int wrong_guesses = 0;
        Word* word;
};