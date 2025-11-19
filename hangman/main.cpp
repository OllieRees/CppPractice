#include "game.cpp"
#include <iostream>

int main(int, char**) {
    WordFetcher* fetcher = new WordFetcherAPI();
    Game* game = new Game(WordGenerator(fetcher).generate_word(), new Config(6));
}
