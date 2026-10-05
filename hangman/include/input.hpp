#pragma once
#include <iostream>
#include <string>

class Inputter {
    public:
        virtual ~Inputter() = default;
        virtual char input_letter(const std::string& prompt = "Enter a letter: ") = 0;
};

class ConsoleInputter : public Inputter {
    public:
        ConsoleInputter(std::istream& in = std::cin, std::ostream& out = std::cout, std::string default_prompt = "Enter a letter: ")
            : in(in), out(out), default_prompt(std::move(default_prompt)) {}

        char input_letter(const std::string& prompt = "") override;

    private:
        std::istream& in;
        std::ostream& out;
        std::string default_prompt;
};