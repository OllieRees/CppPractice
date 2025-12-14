#include "word.hpp"

class Settings {
    public:
        Settings(int max_lives): max_lives(max_lives) {}
    private:
        int max_lives;
};

class Game {
    public:
        Game(Word* word, int max_lives): word(word), settings(new Settings(max_lives)) {}
        Word* get_word() { return word; }
    private:
        Word* word;
        Settings* settings;
};