#include "fizzbuzz.h"

class FizzBuzzTest : public FizzBuzz {
public:
      string static getString(int number) {
          return FizzBuzz::getString(number);
      }
};

#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(getString)
{
    BOOST_CHECK(FizzBuzzTest::getString(1) == "1");
    BOOST_CHECK(FizzBuzzTest::getString(2) == "2");
    BOOST_CHECK(FizzBuzzTest::getString(3) == "Fizz");
    BOOST_CHECK(FizzBuzzTest::getString(4) == "4");
    BOOST_CHECK(FizzBuzzTest::getString(5) == "Buzz");
    BOOST_CHECK(FizzBuzzTest::getString(6) == "Fizz");
    BOOST_CHECK(FizzBuzzTest::getString(7) == "7");
    BOOST_CHECK(FizzBuzzTest::getString(10) == "Buzz");
    BOOST_CHECK(FizzBuzzTest::getString(30) == "FizzBuzz");
    BOOST_CHECK(FizzBuzzTest::getString(60) == "FizzBuzz");
    BOOST_CHECK(FizzBuzzTest::getString(-13) == "-13");
}

BOOST_AUTO_TEST_CASE(fizzBuzzWithInt)
{
    BOOST_CHECK(FizzBuzz::fizzBuzz(1, 15) == "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz");

    // If the end is lower than the start, we should get an empty string.
    BOOST_CHECK(FizzBuzz::fizzBuzz(5, 3) == "");
}

BOOST_AUTO_TEST_CASE(fizzBuzzWithString)
{
    BOOST_CHECK(FizzBuzz::fizzBuzz("1", "15") == "1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz");

    // If the end is lower than the start, we should get an empty string.
    BOOST_CHECK(FizzBuzz::fizzBuzz("5", "3") == "");

    // If the end is lower than the start, we should get an empty string.  Use negative numbers.
    BOOST_CHECK(FizzBuzz::fizzBuzz("-3", "-5") == "");

    // If invalid arguments are passed in, it should throw an exception.
    BOOST_CHECK_THROW(FizzBuzz::fizzBuzz("1", "string"), invalid_argument);

    // If invalid arguments are passed in, it should throw an exception.
    BOOST_CHECK_THROW(FizzBuzz::fizzBuzz("string", "1"), invalid_argument);

    // Check what we should be getting
    cout << "Running test" << endl;
    BOOST_CHECK(FizzBuzz::fizzBuzz("1", "3") == "1 2 Fizz");
    cout << "Test passed" << endl;
}
