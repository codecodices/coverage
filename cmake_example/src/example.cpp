#include "example.h"
#include "mysharedlib.h"
#include "mystaticlib.h"

#include <cstdlib>

int main(int argc, char** argv, char** env)
{
    calledFromSharedLib();
    calledFromStaticLib();
    return EXIT_SUCCESS;
}
