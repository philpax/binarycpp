#include <stdio.h>
#include "gates.h"
#include "logic.h"

#define ADD(a, b) B_(ADD_BITS(a, b))
#define NEGATE(a) NEGATE_BITS(a)

int main()
{
    printf("%i\n", ADD(P_1356, NEGATE(P_56)));
}