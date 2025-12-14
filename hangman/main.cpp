#include "word.cpp"
#include <iostream>

int main(int, char**) {
    WordGenerator* generator = new WordGeneratorAPI();
    std::cout << generator->generate_word()->get_word() << std::endl;
}
