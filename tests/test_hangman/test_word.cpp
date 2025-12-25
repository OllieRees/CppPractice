#include "word.hpp"
#include <gtest/gtest.h>

TEST(TestWord, getCharactersNoDuplicates) {
  Word * word = new Word("team");
  EXPECT_EQ(word->get_characters().size(), 4);
}

TEST(TestWord, getCharactersWithDuplicates) {
  Word * word = new Word("hello");
  EXPECT_EQ(word->get_characters().size(), 4);
}