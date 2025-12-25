#include <iostream>
#include <string>
#include <set>


class Word {
    public:
        Word(const std::string& word) : word(word) {}
        std::set<char> get_characters() const;
        bool contains_character(char c) const;
        const size_t length() const { return word.length(); }
        const std::string get_word() const { return word; }
    private:
        const std::string word;    
};

class WordGenerator {
    public:
        virtual Word* generate_word() = 0;
};

class WordGeneratorAPI: public WordGenerator {
    public:
        Word* generate_word();
};