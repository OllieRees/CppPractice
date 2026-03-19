#include "display.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(TestConsoleDisplayWord, NoGuesses) {
    Game* game = new Game(new Word("hello"), 3);
    
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    Console(game).display_word();

    std::cout.rdbuf(prevcoutbuf);

    ASSERT_EQ(buffer.str(), "_ _ _ _ _ \n");
}

TEST(TestConsoleDisplayWord, NoCorrectGuesses) {
    Game* game = new Game(new Word("hello"), 3);
    game->make_guess('t');
    
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    Console(game).display_word();

    std::cout.rdbuf(prevcoutbuf);

    ASSERT_EQ(buffer.str(), "_ _ _ _ _ \n");
}

TEST(TestConsoleDisplayWord, FirstWordCorrect) {
    Game* game = new Game(new Word("hello"), 3);
    game->make_guess('h');
    
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    Console(game).display_word();

    std::cout.rdbuf(prevcoutbuf);

    ASSERT_EQ(buffer.str(), "h _ _ _ _ \n");
}

TEST(TestConsoleDisplayWord, MultipleCorrectGuesses) {
    Game* game = new Game(new Word("hello"), 3);
    game->make_guess('h');
    game->make_guess('l');

    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    Console(game).display_word();

    std::cout.rdbuf(prevcoutbuf);

    ASSERT_EQ(buffer.str(), "h _ l l _ \n");
}

TEST(TestConsoleDisplayWord, AllCorrectGuesses) {
    Game* game = new Game(new Word("hello"), 3);
    game->make_guess('h');
    game->make_guess('l');
    game->make_guess('e');
    game->make_guess('o');

    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    Console(game).display_word();

    std::cout.rdbuf(prevcoutbuf);

    ASSERT_EQ(buffer.str(), "h e l l o \n");
}