#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <string>

using namespace std;

class FizzBuzz {
public:
    string static fizzBuzz(int startingNumber, int endingNumber);
    string static fizzBuzz(string startingNumber, string endingNumber);

protected:
    string static getString(int number);
};

#endif
