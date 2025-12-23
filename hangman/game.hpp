#include "word.hpp"
#include <iostream>
#include <vector>

enum State { in_progress, win, lose };

class Settings {
    public:
        Settings(int max_lives): max_lives(max_lives) {}
        int get_max_lives() const { return max_lives; }
    private:
        int max_lives;
};

class Game {
    public:
        Game(Word* word, int max_lives): word(word), settings(new Settings(max_lives)) {}
        Word* get_word() const { return word; }
        State make_guess(char c);
    private:
        Word* word;
        Settings* settings;
        std::vector<char> guesses;
        int wrong_guesses = 0;
        bool has_lost() const { return wrong_guesses >= settings -> get_max_lives(); }
        bool has_won() const;
};