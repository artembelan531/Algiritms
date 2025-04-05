#include <gtest/gtest.h>
#include "Ascii85.h"

TEST(Ascii85Test, EncodeHelloWorld) {
    std::vector<unsigned char> input = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    
    
    std::string expected = "87cURD_*#4DfTZ)+T";
    
    EXPECT_EQ(encodeToAscii85(input), expected);
}

TEST(Ascii85Test, DecodeHelloWorld) {
    
    std::string input = "87cURD_*#4DfTZ)+T";
    std::vector<unsigned char> expected = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    EXPECT_EQ(decodeFromAscii85(input), expected);
}

TEST(Ascii85Test, EmptyInputEncode) {
    std::vector<unsigned char> input = {};
    EXPECT_EQ(encodeToAscii85(input), "");
}

TEST(Ascii85Test, EmptyInputDecode) {
    std::string input = "";
    std::vector<unsigned char> expected = {};
    EXPECT_EQ(decodeFromAscii85(input), expected);
}

TEST(Ascii85Test, InvalidDecodeThrows) {
    std::string input = "!!!invalid!!!";
    EXPECT_THROW(decodeFromAscii85(input), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
