#include <stdio.h>
#include "gates.h"
#include "logic.h"

#define ADD(a, b) B_(ADD_BITS(a, b))

int main()
{
    printf("%i\n", ADD(P_100, N_80));
}