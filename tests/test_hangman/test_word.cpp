#include "word.hpp"
#include <gtest/gtest.h>
#include <set>

TEST(TestWord, getCharactersNoDuplicates) {
  Word * word = new Word("team");
  std::set<char> actual_char_set = word->get_characters();
  std::set<char> expected_char_set = {'t', 'e', 'a', 'm'};
  EXPECT_EQ(actual_char_set.size(), 4);
  EXPECT_EQ(actual_char_set, expected_char_set);
}

TEST(TestWord, getCharactersWithDuplicates) {
  Word * word = new Word("hello");
  std::set<char> actual_char_set = word->get_characters();
  std::set<char> expected_char_set = {'h', 'e', 'l', 'o'};
  EXPECT_EQ(word->get_characters().size(), 4);
  EXPECT_EQ(word->get_characters(), expected_char_set);
}