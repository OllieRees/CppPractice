#include <string>


class WordFetcher {
    public:
        virtual std::string fetch_word() = 0;
};

class WordFetcherAPI: public WordFetcher {
    public:
        virtual std::string fetch_word();
};

class WordGenerator {
    public:
        WordGenerator(WordFetcher *fetcher) : fetcher(fetcher) {}
        const std::string generate_word();
    private:
        WordFetcher *fetcher;
};