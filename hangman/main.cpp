#include "word.cpp"
#include <iostream>

int main(int, char**) {
    WordFetcher* fetcher = new WordFetcherAPI();
    WordGenerator wg = WordGenerator(fetcher);
    std::cout << wg.generate_word() << std::endl;
}
