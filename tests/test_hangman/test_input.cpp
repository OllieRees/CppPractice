#include "input.hpp"
#include "game.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <sstream>

TEST(TestInput, DefaultPromptUsed) {
    std::istringstream input_stream("a\n");
    std::ostringstream output_stream;
    ConsoleInputter inputter(input_stream, output_stream);

    char result = inputter.input_letter();

    EXPECT_EQ(result, 'a');
    EXPECT_EQ(output_stream.str(), "Enter a letter: ");
}

TEST(TestInput, CustomPromptUsed) {
    std::istringstream input_stream("b\n");
    std::ostringstream output_stream;
    ConsoleInputter inputter(input_stream, output_stream);

    char result = inputter.input_letter("Your guess: ");

    EXPECT_EQ(result, 'b');
    EXPECT_EQ(output_stream.str(), "Your guess: ");
}

TEST(TestInput, NormalizesToLowerCase) {
    std::istringstream input_stream("Z\n");
    std::ostringstream output_stream;
    ConsoleInputter inputter(input_stream, output_stream);

    char result = inputter.input_letter();

    EXPECT_EQ(result, 'z');
}

TEST(TestInput, SkipsLeadingWhitespace) {
    std::istringstream input_stream("   \n\t k\n");
    std::ostringstream output_stream;
    ConsoleInputter inputter(input_stream, output_stream);

    char result = inputter.input_letter();

    EXPECT_EQ(result, 'k');
}

TEST(TestInput, IntegrationWithGame) {
    std::istringstream input_stream("e\ny\n");
    std::ostringstream output_stream;
    ConsoleInputter inputter(input_stream, output_stream);

    Game game(new Word("eye"), 3);

    char guess1 = inputter.input_letter();
    State state1 = game.make_guess(guess1);
    EXPECT_EQ(guess1, 'e');
    EXPECT_EQ(state1, State::in_progress);

    char guess2 = inputter.input_letter();
    State state2 = game.make_guess(guess2);
    EXPECT_EQ(guess2, 'y');
    EXPECT_EQ(state2, State::win);
}

