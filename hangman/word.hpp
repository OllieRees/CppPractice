#include <string>


/***
 * Generates a word for the hangman game.
 */
class WordGenerator {
    public:
        const std::string generate_word();
    private:
        std::string get_word_from_server();
};