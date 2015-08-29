#include <stdio.h>
#include "gates.h"
#include "logic.h"

int main()
{
    printf("%i\n", B_(ADD(P_1356, NEGATE(P_56))));
}