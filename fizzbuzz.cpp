#include "fizzbuzz.h"


string FizzBuzz::fizzBuzz(int startingNumber, int endingNumber)
{
    string returnValue = "";
    for (int count = startingNumber; count <= endingNumber; count++) {
        returnValue += FizzBuzz::getString(count);
        if (count < endingNumber) {
            returnValue += " ";
        }
    }
    return returnValue;
}

string FizzBuzz::fizzBuzz(string startingNumber, string endingNumber) {
    return FizzBuzz::fizzBuzz(stoi(startingNumber), stoi(endingNumber));
}


string FizzBuzz::getString(int number)
{
    string returnValue = "";
    if (number % 15 == 0) {
        returnValue = "FizzBuzz"; 
    } else if (number % 3 == 0) {
        returnValue = "Fizz";
    } else if (number % 5 == 0) {
        returnValue = "Buzz";
    } else {
        returnValue = to_string(number);
    }

    return returnValue;
}
