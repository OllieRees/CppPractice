#include "include/drawer.hpp"
#include <algorithm>

DefaultConsoleHangmanDrawer::DefaultConsoleHangmanDrawer()
    : ConsoleHangmanDrawer(6),
      hangman_lines({
          "  +---+",
          "  |   |",
          "  |   O",
          "  |  /|\\",
          "  |  / \\",
          "========="
      }) {}

void DefaultConsoleHangmanDrawer::draw(int incorrect_guesses, std::ostream& out) {
    if (incorrect_guesses <= 0) {
        return;
    }
    int lines_to_draw = std::min(incorrect_guesses, static_cast<int>(hangman_lines.size()));
    for (int i = 0; i < lines_to_draw; ++i) {
        out << hangman_lines[i] << "\n";
    }
}
