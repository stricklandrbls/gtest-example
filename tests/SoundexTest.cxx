#include <Soundex.h>
#include <gtest/gtest.h>

TEST(Soundex, Retains_Single_Letter_Of_One_Letter_Word) {
    Soundex soundex;
    auto encoded = soundex.encode("A");
    ASSERT_EQ(encoded, "A");
}