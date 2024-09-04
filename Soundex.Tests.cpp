#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) 
{
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) 
{
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Z"), "Z000");
}

TEST(SoundexTest, HandlesMultipleCharacters)
{
    EXPECT_EQ(generateSoundex("Smith"), "S530");
    EXPECT_EQ(generateSoundex("Fletcher "), "F432");
    EXPECT_EQ(generateSoundex("Smyth"), "S530");
    EXPECT_EQ(generateSoundex("Jones"), "J520");
    EXPECT_EQ(generateSoundex("Barnes"), "B652");
    EXPECT_EQ(generateSoundex("Huey"), "H000");
    EXPECT_EQ(generateSoundex("Zoe"), "Z000");
    EXPECT_EQ(generateSoundex("Fay"), "F000");
}

