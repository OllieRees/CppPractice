#include "word.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <set>

using ::testing::Return;
using json = nlohmann::json;

class MockClient : public WordGeneratorAPIClient {
  public:
    MOCK_METHOD(std::string, request_word_from_api, (), (override));
};

TEST(TestWord, getCharactersNoDuplicates) {
  Word * word = new Word("team");
  std::set<char> actualCharSet = word->get_characters();
  std::set<char> expectedCharSet = {'t', 'e', 'a', 'm'};
  EXPECT_EQ(actualCharSet.size(), 4);
  EXPECT_EQ(actualCharSet, expectedCharSet);
}

TEST(TestWord, getCharactersWithDuplicates) {
  Word * word = new Word("hello");
  std::set<char> actual_char_set = word->get_characters();
  std::set<char> expected_char_set = {'h', 'e', 'l', 'o'};
  EXPECT_EQ(word->get_characters().size(), 4);
  EXPECT_EQ(word->get_characters(), expected_char_set);
}

TEST(TestWord, doesContainCharacter) {
    Word * word = new Word("hello");
    EXPECT_TRUE(word->contains_character('h'));
}

TEST(TestWord, doesNotContainCharacter) {
    Word * word = new Word("hello");
    EXPECT_FALSE(word->contains_character('a'));
}

TEST(TestWordGeneratorAPI, generateWord) {
  MockClient client;
  ON_CALL(client, request_word_from_api()).WillByDefault(Return("hello"));
  WordGenerator * word_generator = new WordGeneratorAPI(&client);
  Word * word = word_generator->generate_word();
  EXPECT_EQ(word->get_word(), "hello");
}