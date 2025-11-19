#include <string>


class Word {
    public:
        Word(const std::string& word) : word(word) {}
        const std::string& get_word() const { return word; }
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