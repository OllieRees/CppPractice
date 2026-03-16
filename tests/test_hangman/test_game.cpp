#include "game.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockClient : public WordGeneratorAPIClient {
  public:
    MOCK_METHOD(std::string, request_word_from_api, (), (override));
};

TEST(TestGame, makeGuessCorrect) {
  Game * game = new Game(new Word("hello"), 1);
  EXPECT_EQ(game->make_guess('h'), State::in_progress);
}

TEST(TestGame, hasLost) {
  Game * game = new Game(new Word("eye"), 1);
  EXPECT_EQ(game->make_guess('i'), State::lose);
}

TEST(TestGame, hasWon) {
  Game * game = new Game(new Word("eye"), 1);
  game->make_guess('e');
  State state = game->make_guess('y');
  EXPECT_EQ(state, State::win);
}

TEST(TestGame, hasWonWithSomeWrongGuesses) {
  Game * game = new Game(new Word("eye"), 2);
  game->make_guess('e');
  game->make_guess('x');
  State state = game->make_guess('y');
  EXPECT_EQ(state, State::win);
}

TEST(TestSettings, getWord) {
  Game * game = new Game(new Word("hello"), 1);
  EXPECT_EQ(game->get_word()->get_word(), "hello");
}