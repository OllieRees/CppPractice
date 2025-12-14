#include <iostream>
#include <string>
#include <set>


class Word {
    public:
        Word(const std::string& word) : word(word) {}
        std::set<char> get_characters() { return std::set<char>(this -> word.begin(), this -> word.end()); }
        bool contains_character(char c) { return this -> word.find(c) != std::string::npos; }
        const size_t length() const { return word.length(); }
        const std::string get_word() {return word; }
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