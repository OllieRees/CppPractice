#include <iostream>
#include <string>
#include <set>


class Word {
    public:
        Word(const std::string& word) : word(word) {}
        std::set<char> get_characters() { return std::set<char>(this -> word.begin(), this -> word.end()); }
        const std::string& get_word() const { return word; }
        const size_t length() const { return word.length(); }
    private:
        const std::string word;    
};

class WordFetcher {
    public:
        virtual Word* fetch_word() = 0;
};

class WordFetcherAPI: public WordFetcher {
    public:
        virtual Word* fetch_word();
};

class WordGenerator {
    public:
        WordGenerator(WordFetcher *fetcher) : fetcher(fetcher) {}
        Word* generate_word();
    private:
        WordFetcher *fetcher;
};