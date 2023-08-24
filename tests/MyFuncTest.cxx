#include <MyFunc.h>
#include <gmock/gmock.h>
#include <iostream>
#include <unordered_map>

TEST(MyFuncTest, Returns69) {
    EXPECT_EQ(my_func(), 69);
}
TEST(MyFuncTest, CanInstantiateClass) {
    MyFuncClass mfc { 10 };
}
TEST(MyFuncTest, Returns79) {
    MyFuncClass mfc { 10 };
    EXPECT_EQ(my_func(mfc), 79);
}

class Soundex {
public:
    static const size_t MaxCodeLength { 4 };

    std::string encode(const std::string& word) const { 
    // return zeroPad(word); // Old Implementation

    /* 
        == TDD Three Rule Cycle - Green (Writing a failing test) ==
        In order to complete the Green phase, we must write production code
        that successfully passes the test written.
    */
        return zeroPad(head(word) + encodedDigits(tail(word)));
    }
private:
    std::string zeroPad(const std::string& word) const { 
        auto needsZeroPad = MaxCodeLength - word.length();
        return word + std::string(needsZeroPad, '0'); 
    }
    std::string head(const std::string& word) const {
        return word.substr(0,1);
    }
    std::string tail(const std::string& word) const {
        return word.substr(1);
    }
    bool isComplete(const std::string& encoding) const {
        return encoding.length() == MaxCodeLength - 1;
    }
    std::string encodedDigits(const std::string& word) const {
        std::string encoding;
        for(auto letter : word) {
            if(isComplete(encoding)) break;
            encoding += encodedDigit(letter);
        }
        return encoding;
    }
    std::string encodedDigit(char letter) const { 
        // if(letter == 'c' ) return "2";
        // return "1"; 
        /* ^^ Extremely poor design but good TDD incrementalism that leads to a 
            hash-based collection for encoding letters.
        */
       std::unordered_map<char, std::string> encodings {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, 
            {'s', "2"}, {'x', "2"}, {'z', "2"}, {'q', "2"},
            {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, 
            {'n', "5"}, {'r', "6"}
       };
       auto it = encodings.find(letter);

       return it == encodings.end() ? "" : encodings.find(letter)->second;
    }
};

/**
 * @brief TEST Fixture class for `Soundex`
*/
class Soundex_Fixture: public ::testing::Test {
public:
    Soundex f_soundex;
};


TEST(SoundexEncoding_NonFixtured, Retains_sole_letter_of_one_letter_word) {
    Soundex soundex;
    auto encoded = soundex.encode("A");

    ASSERT_EQ(encoded, "A000");
}

TEST(SoundexEncoding_NonFixtured, Pads_zeros_to_ensure_three_digits) {
    Soundex soundex;
    auto encoded = soundex.encode("I");

    ASSERT_EQ(encoded, "I000");
}

TEST_F(Soundex_Fixture, Retains_sole_letter_of_one_letter_word) {
    ASSERT_EQ(f_soundex.encode("A"), "A000");
}

TEST_F(Soundex_Fixture, Pads_zeros_to_ensure_three_digits) {
    ASSERT_EQ(f_soundex.encode("I"), "I000");
}

TEST_F(Soundex_Fixture, Replaces_consonants_with_appropriate_digits) {
    /* 
        == TDD Three Rule Cycle - Red (Writing a failing test) ==
        We want to move forward with developing the spec of a Soundex class
        by address the soundex rule #2.

        This test points towards the expected result of the new functionality
        and will fail because it's not implemented.
    */
    // ASSERT_EQ(f_soundex.encode("Ab"), "A100");

    // EXPECT_EQ(f_soundex.encode("Ab"), "A100");
    // EXPECT_EQ(f_soundex.encode("Ac"), "A200");
    // EXPECT_EQ(f_soundex.encode("Ad"), "A300");
    ASSERT_EQ(f_soundex.encode("Ax"), "A200");
}

TEST_F(Soundex_Fixture, Replaces_multiple_consonants_with_digits) {
    ASSERT_EQ(f_soundex.encode("Acdl"), "A234");
}

TEST_F(Soundex_Fixture, Limits_length_to_four_characters) {
    ASSERT_EQ(f_soundex.encode("Dcdlb").length(), 4u);
}