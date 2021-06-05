#include "fizzbuzz.h"

#include <iostream>
#include <string>

/*
 * Write a program that prints the numbers from 1 to 100. But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”. For numbers which are multiples of both three and five print “FizzBuzz”.
 */

using namespace std;

int main(int argc, char** argv, char** env)
{
    int returnValue = EXIT_SUCCESS;

    int lower = 1;
    int upper = 100;

    if (argc == 3) {
        try {
            cout << FizzBuzz::fizzBuzz(argv[1], argv[2]) << endl;
        } catch (std::invalid_argument const& e) {
            cout << "Invalid argument: " << e.what() << endl;
            returnValue = EXIT_FAILURE;
        }
    } else {
        cout << FizzBuzz::fizzBuzz(lower, upper) << endl;
    }

    return returnValue;
}
