#include "include/input.hpp"
#include <cctype>

char ConsoleInputter::input_letter(const std::string& prompt) {
    const std::string& active_prompt = prompt.empty() ? default_prompt : prompt;
    out << active_prompt;

    char c = '\0';
    if (in >> c) {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return c;
}