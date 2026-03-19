#include "display.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

class TestConsoleDisplayWord: public testing::Test {
    protected:
        void SetUp() override {
            this->prevcoutbuf = std::cout.rdbuf();
            std::cout.rdbuf(this->buffer.rdbuf());
        }
        void TearDown() override {}
    public:
        std::stringstream buffer;
        std::streambuf* prevcoutbuf;
};

TEST_F(TestConsoleDisplayWord, NoGuesses) {
    Game* game = new Game(new Word("hello"), 3);
    Console(game).display_word();

    std::cout.rdbuf(this->prevcoutbuf);

    ASSERT_EQ(this->buffer.str(), "_ _ _ _ _ \n");
}

TEST_F(TestConsoleDisplayWord, NoCorrectGuesses) {
    Game* game = new Game(new Word("hello"), 3);
    game->make_guess('t');

    Console(game).display_word();

    std::cout.rdbuf(this->prevcoutbuf);

    ASSERT_EQ(this->buffer.str(), "_ _ _ _ _ \n");
}

TEST_F(TestConsoleDisplayWord, FirstWordCorrect) {
    Game* game = new Game(new Word("hello"), 3);
    game->make_guess('h');
    
    Console(game).display_word();

    std::cout.rdbuf(this->prevcoutbuf);

    ASSERT_EQ(this->buffer.str(), "h _ _ _ _ \n");
}

TEST_F(TestConsoleDisplayWord, MultipleCorrectGuesses) {
    Game* game = new Game(new Word("hello"), 3);
    game->make_guess('h');
    game->make_guess('l');

    Console(game).display_word();

    std::cout.rdbuf(this->prevcoutbuf);

    ASSERT_EQ(this->buffer.str(), "h _ l l _ \n");
}

TEST_F(TestConsoleDisplayWord, AllCorrectGuesses) {
    Game* game = new Game(new Word("hello"), 3);
    game->make_guess('h');
    game->make_guess('l');
    game->make_guess('e');
    game->make_guess('o');

    Console(game).display_word();

    std::cout.rdbuf(this->prevcoutbuf);

    ASSERT_EQ(this->buffer.str(), "h e l l o \n");
}