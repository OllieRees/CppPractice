#include "drawer.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(TestDefaultConsoleHangmanDrawer, NoIncorrectGuesses) {
    DefaultConsoleHangmanDrawer drawer;
    std::stringstream out;
    drawer.draw(0, out);
    EXPECT_EQ(out.str(), "");
}

TEST(TestDefaultConsoleHangmanDrawer, NegativeIncorrectGuesses) {
    DefaultConsoleHangmanDrawer drawer;
    std::stringstream out;
    drawer.draw(-2, out);
    EXPECT_EQ(out.str(), "");
}

TEST(TestDefaultConsoleHangmanDrawer, OneIncorrectGuess) {
    DefaultConsoleHangmanDrawer drawer;
    std::stringstream out;
    drawer.draw(1, out);
    EXPECT_EQ(out.str(), "  +---+\n");
}

TEST(TestDefaultConsoleHangmanDrawer, ThreeIncorrectGuesses) {
    DefaultConsoleHangmanDrawer drawer;
    std::stringstream out;
    drawer.draw(3, out);
    std::string expected = 
        "  +---+\n"
        "  |   |\n"
        "  |   O\n";
    EXPECT_EQ(out.str(), expected);
}

TEST(TestDefaultConsoleHangmanDrawer, FullHangmanDrawn) {
    DefaultConsoleHangmanDrawer drawer;
    std::stringstream out;
    drawer.draw(6, out);
    std::string expected = 
        "  +---+\n"
        "  |   |\n"
        "  |   O\n"
        "  |  /|\\\n"
        "  |  / \\\n"
        "=========\n";
    EXPECT_EQ(out.str(), expected);
}

TEST(TestDefaultConsoleHangmanDrawer, ExceedingMaxLinesClamps) {
    DefaultConsoleHangmanDrawer drawer;
    std::stringstream out;
    drawer.draw(10, out);
    std::string expected = 
        "  +---+\n"
        "  |   |\n"
        "  |   O\n"
        "  |  /|\\\n"
        "  |  / \\\n"
        "=========\n";
    EXPECT_EQ(out.str(), expected);
}

TEST(TestDefaultConsoleHangmanDrawer, GetLinesCount) {
    DefaultConsoleHangmanDrawer drawer;
    EXPECT_EQ(drawer.get_lines().size(), 6);
}

