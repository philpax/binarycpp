#include <stdio.h>
#include "gates.h"
#include "logic.h"

#define ADD(a, b) B_(ADD_BITS(a, b))

int main()
{
    printf("%i\n", ADD(P_1356, N_56));
}