/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/
TEST(GuesserTest, constructorNormal)
{
    Guesser myGuesser("helloWorld");
    int actual = myGuesser.remaining();
    ASSERT_EQ(3, actual);
}
TEST(GuesserTest, guessOneCorrect)
{
    Guesser myGuesser("helloWorld");
    bool result = myGuesser.match("helloWorld");
    int actual = myGuesser.remaining();
    ASSERT_EQ(3, actual);
}
TEST(GuesserTest, guessOneCorrectMatch)
{
    Guesser myGuesser("helloWorld");
    bool result = myGuesser.match("helloWorld");
    bool actual = myGuesser.match("helloWorld");
    ASSERT_EQ(true, actual);
}
TEST(GuesserTest, guessOneIncorrect)
{
    Guesser myGuesser("helloWorlda");
    bool result = myGuesser.match("helloWorldb");
    int actual = myGuesser.remaining();
    ASSERT_EQ(2, actual);
}
TEST(GuesserTest, guessOneIncorrectMatch)
{
    Guesser myGuesser("helloWorlda");
    bool result = myGuesser.match("helloWorldb");
    bool actual = myGuesser.match("helloWorldb");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, guessThreeIncorrect)
{
    Guesser myGuesser("helloWorlda");
    bool result = myGuesser.match("helloWorldb");
    result = myGuesser.match("helloWorldc");
    result = myGuesser.match("helloWorldd");
    int actual = myGuesser.remaining();
    ASSERT_EQ(0, actual);
}
TEST(GuesserTest, guessFourIncorrect)
{
    Guesser myGuesser("helloWorlda");
    bool result = myGuesser.match("helloWorldb");
    result = myGuesser.match("helloWorldc");
    result = myGuesser.match("helloWorldd");
    result = myGuesser.match("helloWorlde");
    int actual = myGuesser.remaining();
    ASSERT_EQ(0, actual);
}

TEST(GuesserTest, guessThreeIncorrectThenCorrect)
{
    Guesser myGuesser("helloWorlda");
    bool result = myGuesser.match("helloWorldb");
    result = myGuesser.match("helloWorldc");
    result = myGuesser.match("helloWorld");
    int actual = myGuesser.remaining();
    ASSERT_EQ(0, actual);
}
TEST(GuesserTest, guessThreeIncorrectThenCorrectMatch)
{
    Guesser myGuesser("helloWorlda");
    bool result = myGuesser.match("helloWorldb");
    result = myGuesser.match("helloWorldc");
    bool actual = myGuesser.match("helloWorld");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, guessOneIncorrectThenCorrect)
{
    Guesser myGuesser("helloWorlda");
    bool result = myGuesser.match("helloWorldb");
    result = myGuesser.match("helloWorlda");
    int actual = myGuesser.remaining();
    ASSERT_EQ(3, actual);
}
TEST(GuesserTest, guessOneIncorrectThenCorrectMatch)
{
    Guesser myGuesser("helloWorlda");
    bool result = myGuesser.match("helloWorldb");
    bool actual = myGuesser.match("helloWorlda");
    ASSERT_EQ(true, actual);
}    
TEST(GuesserTest, truncatedSecretFail)
{
    Guesser myGuesser("helloWorldaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    bool actual = myGuesser.match("helloWorldaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, truncatedSecretSuccess)
{
    Guesser myGuesser("helloWorldaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    bool actual = myGuesser.match("helloWorldaaaaaaaaaaaaaaaaaaaaa");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, bruteForceMatch)
{
    Guesser myGuesser("helloWorld");
    bool actual = myGuesser.match("helloASDF!");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, bruteForceThenCorrect)
{
    Guesser myGuesser("helloWorld");
    bool actual = myGuesser.match("helloASDF!");
    actual = myGuesser.match("helloWorld");
    ASSERT_EQ(true, actual);
}
TEST(GuesserTest, shortGuess)
{
    Guesser myGuesser("helloWorld");
    bool actual = myGuesser.match("hello");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, longGuess)
{
    Guesser myGuesser("helloWorld");
    bool actual = myGuesser.match("helloWorldASDF");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, reallyLongGuess)
{
    Guesser myGuesser("helloWorld");
    bool actual = myGuesser.match("helloWorldASDFFFFFFFFFFFFFF");
}
TEST(GuesserTest, emptyStringGuess)
{
    Guesser myGuesser("helloWorld");
    bool actual = myGuesser.match("");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, emptyStringSecret)
{
    Guesser myGuesser("");
    bool actual = myGuesser.match("helloWorld");
    ASSERT_EQ(false, actual);
}
TEST(GuesserTest, emptyStringBoth)
{
    Guesser myGuesser("");
    bool actual = myGuesser.match("");
    ASSERT_EQ(true, actual);
}


/*
things to test:
- constructor:
    - secret is truncated to 32 characters
    - remaining is 3 (use int remaining)
- distance:
    - make sure this doesn't segfault
    - test with identical strings
    - test with strings of different lengths
    - test with strings of different characters
    - test 10 letter secret, 100 letter guess


*/