#include <string>


class Word {
    public:
        Word(const std::string& word) : word(word) {}
        const std::string& get_word() const { return word; }
        const size_t get_length() const { return word.length(); }
        bool contains_character(char c) const { return word.find(c) != std::string::npos; }
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