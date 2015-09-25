#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <sys/mman.h>

#include "logic.h"
#include "assembly.h"

#define INC_FN(x) ADD(I(x), P(2))
#define COND_FN(x) LT(I(x), P(10))
#define EXEC_GENERATE_FN(x) void JOIN(function, B(I(x)))() { printf("Compile-time for loop: %i\n", B(I(x))); }
FOR_EACH(P(0), INC_FN, COND_FN, EXEC_GENERATE_FN)

int main()
{
    printf("- Addition / subtraction -\n");
    printf("24 + 20 - 2 = %i\n", B(SUB(ADD(P(24), P(20)), P(2))));
    printf("__LINE__: %i; __LINE__ + 2: %i\n", __LINE__, B(ADD(P(__LINE__), P(2))));

    printf("- Shifting -\n");
    printf("(1 << 4) + 4 = %i\n", B(ADD(SHL(P(1), P(4)), P(4))));
    printf("(64 >> 2) + 4 = %i\n", B(ADD(SHR(P(64), P(2)), P(4))));

    printf("- Binary and -\n");
    printf("19 & 17 = %i\n", B(BAND(P(19), P(17))));

    printf("- Multiplication -\n");
    printf("6 * 7 = %i\n", B(MUL(P(6), P(7))));
    printf("40 * 40 = %i\n", B(MUL(P(20), P(40))));
    printf("40 * -40 = %i\n", B(MUL(P(20), N(40))));

    printf("- Powers -\n");
    printf("9^2 = %i\n", B(SQUARE(P(9))));
    printf("9^3 = %i\n", B(CUBE(P(9))));
    printf("1^3 + 12^3 = %i\n",
        B(ADD(CUBE(P(1)), CUBE(P(12)))));
    printf("9^3 + 10^3 = %i\n",
        B(ADD(CUBE(P(9)), CUBE(P(10)))));

    printf("- Equality -\n");
    printf("42 == 42: %i\n", EQUAL(P(42), P(42)));
    printf("23 == 42: %i\n", EQUAL(P(23), P(42)));

    printf("- Greater than -\n");
    printf("42 > 43: %i\n", GT(P(42), P(43)));
    printf("42 > 42: %i\n", GT(P(42), P(42)));
    printf("42 > 41: %i\n", GT(P(42), P(41)));
    printf("42 > -1: %i\n", GT(P(42), N(1)));
    printf("0 > -1: %i\n", GT(P(0), N(1)));
    printf("-1 > -2: %i\n", GT(N(1), N(2)));

    printf("- Greater than or equal -\n");
    printf("42 >= 43: %i\n", GE(P(42), P(43)));
    printf("42 >= 42: %i\n", GE(P(42), P(42)));
    printf("42 >= 41: %i\n", GE(P(42), P(41)));
    printf("42 >= -1: %i\n", GE(P(42), N(1)));
    printf("0 >= -1: %i\n", GE(P(0), N(1)));
    printf("-1 >= -2: %i\n", GE(N(1), N(2)));

    printf("- Less than -\n");
    printf("43 < 42: %i\n", LT(P(43), P(42)));
    printf("42 < 42: %i\n", LT(P(42), P(42)));
    printf("41 < 42: %i\n", LT(P(41), P(42)));
    printf("-1 < 42: %i\n", LT(N(1), P(42)));
    printf("-1 < 0: %i\n", LT(N(1), P(0)));
    printf("-2 < -1: %i\n", LT(N(2), N(1)));

    printf("- Less than or equal -\n");
    printf("43 <= 42: %i\n", LE(P(43), P(42)));
    printf("42 <= 42: %i\n", LE(P(42), P(42)));
    printf("41 <= 42: %i\n", LE(P(41), P(42)));
    printf("-1 <= 42: %i\n", LE(N(1), P(42)));
    printf("-1 <= 0: %i\n", LE(N(1), P(0)));
    printf("-2 <= -1: %i\n", LE(N(2), N(1)));

    printf("- If statements -\n");
    IF(EQUAL(P(42), MUL(P(21), P(2))),
        printf("42 == 21 * 2\n"));
    IF(EQUAL(P(42), MUL(P(21), P(3))),
        printf("42 == 21 * 3\n"));
    IF_ELSE(EQUAL(P(3), P(4)),
        printf("3 == 4\n"),
        printf("3 != 4\n"));

    #define EXEC_CALL_FN(x) JOIN(function, B(I(x)))();
    FOR_EACH(P(0), INC_FN, COND_FN, EXEC_CALL_FN)

    uint8_t bytes[] = {
        PUSH(EBP),
        MOV_RR(EBP, ESP),
        MOV_RI(EAX, P(12)),
        MOV_RI(EDX, P(30)),
        ADD_RR(EAX, EDX),
        POP(EBP),
        RET()
    };

    uint8_t* buffer = (uint8_t*)mmap(
        NULL, sizeof(bytes), PROT_READ|PROT_WRITE|PROT_EXEC,
        MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);

    memcpy(buffer, bytes, sizeof(bytes));

    typedef int (*FunctionType)();
    printf("Function call: %i\n", ((FunctionType)buffer)());

    munmap(buffer, sizeof(bytes));
}