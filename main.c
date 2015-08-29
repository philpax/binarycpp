#include <stdio.h>
#include "gates.h"
#include "logic.h"

#define MUL_BY_5(x) ADD(ADD(ADD(ADD(I(x), I(x)), I(x)), I(x)), I(x))

int main()
{
    printf("%i\n", B(SUB(ADD(P(24), P(20)), P(2))));
    printf("%i\n", B(MUL_BY_5(P(4))));
    printf("__LINE__: %i; __LINE__ + 2: %i\n", __LINE__, B(ADD(P(__LINE__), P(2))));
}