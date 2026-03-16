#include <iostream>
#include <string>
#include <set>
#include <nlohmann/json.hpp>


class Word {
    public:
        Word(const std::string& word) : word(word) {}
        std::set<char> get_characters() const;
        bool contains_character(char c) const;
        const std::string get_word() const { return word; }
    private:
        const std::string word;    
};

class WordGeneratorAPIClient {
    public:
        virtual std::string request_word_from_api() = 0;
};

class WordGeneratorRandomWordClient: public WordGeneratorAPIClient {
    public:
        std::string request_word_from_api();
};

class WordGenerator {
    public:
        virtual Word* generate_word() = 0;
};

class WordGeneratorAPI: public WordGenerator {
    public:
        WordGeneratorAPI(WordGeneratorAPIClient* client): client(client) {}
        Word* generate_word();
    private: 
        WordGeneratorAPIClient* client;
};