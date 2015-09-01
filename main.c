#include <stdio.h>
#include "logic.h"

int main()
{
    printf("%i\n", B(SUB(ADD(P(24), P(20)), P(2))));
    printf("%i\n", B(ADD(SHL(P(1), P(4)), P(4))));
    printf("%i\n", B(ADD(SHR(P(64), P(2)), P(4))));
    printf("%i\n", B(BAND(P(19), P(17))));
    printf("%i\n", B(MUL(P(6), P(7))));
    printf("%i\n", B(MUL(P(20), P(40))));
    printf("%i\n", B(MUL(P(20), N(40))));
    printf("%i\n", B(SQUARE(P(9))));
    printf("%i\n", B(CUBE(P(9))));
    printf("__LINE__: %i; __LINE__ + 2: %i\n", __LINE__, B(ADD(P(__LINE__), P(2))));
}