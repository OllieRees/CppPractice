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

class MockConsoleHangmanDrawer : public ConsoleHangmanDrawer {
    public:
        MockConsoleHangmanDrawer(): ConsoleHangmanDrawer(6) {};
        MOCK_METHOD(void, draw, (int incorrect_guesses, std::ostream& out), (override));
};

TEST(TestConsoleDisplayHangman, CallsDrawerWithWrongGuesses) {
    Game* game = new Game(new Word("hello"), 5);
    game->make_guess('x'); // wrong 1
    game->make_guess('z'); // wrong 2
    game->make_guess('h'); // correct

    MockConsoleHangmanDrawer mock_drawer;
    EXPECT_CALL(mock_drawer, draw(2, testing::_)).Times(1);

    Console console(game, &mock_drawer);
    console.display_hangman();
}

TEST_F(TestConsoleDisplayWord, DisplayHangmanDefaultDrawer) {
    Game* game = new Game(new Word("hello"), 6);
    game->make_guess('x');

    Console console(game);
    console.display_hangman();

    std::cout.rdbuf(this->prevcoutbuf);

    ASSERT_EQ(this->buffer.str(), "  +---+\n");
}

TEST(TestDisplay, GetMaxLives) {
    Game* game = new Game(new Word("hello"), 5);
    Console console(game);
    EXPECT_EQ(console.get_max_lives(), 5);
}

TEST(TestConsole, ThrowsWhenGameMaxLivesExceedsDrawerMaxAllowedLives) {
    Game* game = new Game(new Word("hello"), 7);
    MockConsoleHangmanDrawer mock_drawer;
    std::cout << "Drawer Max Lives: " << mock_drawer.get_max_allowed_lives() << std::endl;
    EXPECT_THROW(Console(game, &mock_drawer), std::invalid_argument);
}
