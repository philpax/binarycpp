#include <stdio.h>
#include "gates.h"
#include "logic.h"

int main()
{
    printf("%i\n", B(SUB(ADD(P(24), P(20)), P(2))));
    printf("__LINE__: %i; __LINE__ + 2: %i\n", __LINE__, B(ADD(P(__LINE__), P(2))));
}