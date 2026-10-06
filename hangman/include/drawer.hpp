#pragma once

#include <iostream>
#include <string>
#include <vector>

class ConsoleHangmanDrawer {
    public:
        ConsoleHangmanDrawer(const int max_allowed_lives): max_allowed_lives(max_allowed_lives) {}
        virtual ~ConsoleHangmanDrawer() = default;
        virtual void draw(int incorrect_guesses, std::ostream& out = std::cout) = 0;
        virtual const int get_max_allowed_lives() const { return max_allowed_lives; }
    private:
        const int max_allowed_lives;
};

class DefaultConsoleHangmanDrawer : public ConsoleHangmanDrawer {
    public:
        DefaultConsoleHangmanDrawer();
        void draw(int incorrect_guesses, std::ostream& out = std::cout) override;
        const std::vector<std::string>& get_lines() const { return hangman_lines; }
    private:
        std::vector<std::string> hangman_lines;
};
