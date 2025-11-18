#include "word.cpp"
#include <iostream>

int main(int, char**) {
    WordGenerator wg = WordGenerator();
    std::cout << wg.generate_word() << std::endl;
}
