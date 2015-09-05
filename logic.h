#include "gates.h"
#include "number.h"
#include "control_flow.h"
/* Addition */
#define ADD_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    FULL_ADD_OUT(a0, b0, \
     FULL_ADD_CARRY(a1, b1, \
     FULL_ADD_CARRY(a2, b2, \
     FULL_ADD_CARRY(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     )))))))))))\
    ),\
    FULL_ADD_OUT(a1, b1, \
     FULL_ADD_CARRY(a2, b2, \
     FULL_ADD_CARRY(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     ))))))))))\
    ),\
    FULL_ADD_OUT(a2, b2, \
     FULL_ADD_CARRY(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     )))))))))\
    ),\
    FULL_ADD_OUT(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     ))))))))\
    ),\
    FULL_ADD_OUT(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     )))))))\
    ),\
    FULL_ADD_OUT(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     ))))))\
    ),\
    FULL_ADD_OUT(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     )))))\
    ),\
    FULL_ADD_OUT(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     ))))\
    ),\
    FULL_ADD_OUT(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     )))\
    ),\
    FULL_ADD_OUT(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     ))\
    ),\
    FULL_ADD_OUT(a10, b10, \
     FULL_ADD_CARRY(a11, b11, 0\
     )\
    ),\
    FULL_ADD_OUT(a11, b11, \
     \
     0\
    )
#define ADD(a, b) ADD_BITS(a, b)
/* Negation */
#define NEGATE_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    ADD_BITS(\
     NOT(a0),\
     NOT(a1),\
     NOT(a2),\
     NOT(a3),\
     NOT(a4),\
     NOT(a5),\
     NOT(a6),\
     NOT(a7),\
     NOT(a8),\
     NOT(a9),\
     NOT(a10),\
     NOT(a11),\
     0, \
     0, \
     0, \
     0, \
     0, \
     0, \
     0, \
     0, \
     0, \
     0, \
     0, \
     1\
    )
#define NEGATE(a) NEGATE_BITS(a)
/* Subtraction */
#define SUB_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    FE(ADD_BITS, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, \
     NEGATE_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11))
#define SUB(a, b) SUB_BITS(a, b)
/* Shift left */
#define SHL_0_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
#define SHL_0(a) SHL_0_BITS(a)
#define SHL_1_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, 0
#define SHL_1(a) SHL_1_BITS(a)
#define SHL_2_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, 0, 0
#define SHL_2(a) SHL_2_BITS(a)
#define SHL_3_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a3, a4, a5, a6, a7, a8, a9, a10, a11, 0, 0, 0
#define SHL_3(a) SHL_3_BITS(a)
#define SHL_4_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a4, a5, a6, a7, a8, a9, a10, a11, 0, 0, 0, 0
#define SHL_4(a) SHL_4_BITS(a)
#define SHL_5_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a5, a6, a7, a8, a9, a10, a11, 0, 0, 0, 0, 0
#define SHL_5(a) SHL_5_BITS(a)
#define SHL_6_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a6, a7, a8, a9, a10, a11, 0, 0, 0, 0, 0, 0
#define SHL_6(a) SHL_6_BITS(a)
#define SHL_7_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a7, a8, a9, a10, a11, 0, 0, 0, 0, 0, 0, 0
#define SHL_7(a) SHL_7_BITS(a)
#define SHL_8_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a8, a9, a10, a11, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_8(a) SHL_8_BITS(a)
#define SHL_9_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a9, a10, a11, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_9(a) SHL_9_BITS(a)
#define SHL_10_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a10, a11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_10(a) SHL_10_BITS(a)
#define SHL_11_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_11(a) SHL_11_BITS(a)
#define SHL_12_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_12(a) SHL_12_BITS(a)
#define SHL(a, b) JOIN(JOIN(SHL_, B(I(b))), _BITS)(a)
/* Shift right */
#define SHR_0_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
#define SHR_0(a) SHR_0_BITS(a)
#define SHR_1_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
#define SHR_1(a) SHR_1_BITS(a)
#define SHR_2_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
#define SHR_2(a) SHR_2_BITS(a)
#define SHR_3_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, a0, a1, a2, a3, a4, a5, a6, a7, a8
#define SHR_3(a) SHR_3_BITS(a)
#define SHR_4_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, a0, a1, a2, a3, a4, a5, a6, a7
#define SHR_4(a) SHR_4_BITS(a)
#define SHR_5_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, a0, a1, a2, a3, a4, a5, a6
#define SHR_5(a) SHR_5_BITS(a)
#define SHR_6_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, 0, a0, a1, a2, a3, a4, a5
#define SHR_6(a) SHR_6_BITS(a)
#define SHR_7_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, 0, 0, a0, a1, a2, a3, a4
#define SHR_7(a) SHR_7_BITS(a)
#define SHR_8_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, 0, 0, 0, a0, a1, a2, a3
#define SHR_8(a) SHR_8_BITS(a)
#define SHR_9_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, a0, a1, a2
#define SHR_9(a) SHR_9_BITS(a)
#define SHR_10_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, a0, a1
#define SHR_10(a) SHR_10_BITS(a)
#define SHR_11_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, a0
#define SHR_11(a) SHR_11_BITS(a)
#define SHR_12_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHR_12(a) SHR_12_BITS(a)
#define SHR(a, b) JOIN(JOIN(SHR_, B(I(b))), _BITS)(a)
/* Expansion */
#define EXPAND(a) \
    a, a, a, a, a, a, a, a, a, a, a, a
/* Binary and */
#define BAND_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    AND(a0, b0), AND(a1, b1), AND(a2, b2), AND(a3, b3), AND(a4, b4), AND(a5, b5), AND(a6, b6), AND(a7, b7), AND(a8, b8), AND(a9, b9), AND(a10, b10), AND(a11, b11)
#define BAND(a, b) BAND_BITS(a, b)
/* Multiplication */
#define MUL_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    ADD(SHL(BAND(EXPAND(a11), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(0)), \
    ADD(SHL(BAND(EXPAND(a10), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(1)), \
    ADD(SHL(BAND(EXPAND(a9), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(2)), \
    ADD(SHL(BAND(EXPAND(a8), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(3)), \
    ADD(SHL(BAND(EXPAND(a7), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(4)), \
    ADD(SHL(BAND(EXPAND(a6), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(5)), \
    ADD(SHL(BAND(EXPAND(a5), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(6)), \
    ADD(SHL(BAND(EXPAND(a4), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(7)), \
    ADD(SHL(BAND(EXPAND(a3), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(8)), \
    ADD(SHL(BAND(EXPAND(a2), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(9)), \
    ADD(SHL(BAND(EXPAND(a1), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(10)), \
    ADD(SHL(BAND(EXPAND(a0), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)), P(11)), \
    P(0) \
    ))))))))))))
#define MUL(a, b) MUL_BITS(a, b)
#define SQUARE(x) MUL(I(x), I(x))
#define CUBE(x) MUL(I(x), SQUARE(I(x)))
/* Equality */
#define EQUAL_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    AND(XNOR(a0, b0), \
    AND(XNOR(a1, b1), \
    AND(XNOR(a2, b2), \
    AND(XNOR(a3, b3), \
    AND(XNOR(a4, b4), \
    AND(XNOR(a5, b5), \
    AND(XNOR(a6, b6), \
    AND(XNOR(a7, b7), \
    AND(XNOR(a8, b8), \
    AND(XNOR(a9, b9), \
    AND(XNOR(a10, b10), \
    AND(XNOR(a11, b11), \
    1))))))))))))
#define EQUAL(a, b) EQUAL_BITS(a, b)
/* Greater than */
#define GT_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    OR(AND(NOT(a0), b0), \
    OR(AND(a1, NOT(b1)), \
    OR(AND(XNOR(a1, b1), AND(a2, NOT(b2))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(a3, NOT(b3)))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(a4, NOT(b4))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(a5, NOT(b5)))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(a6, NOT(b6))))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(a7, NOT(b7)))))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(XNOR(a7, b7), AND(a8, NOT(b8))))))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(XNOR(a7, b7), AND(XNOR(a8, b8), AND(a9, NOT(b9)))))))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(XNOR(a7, b7), AND(XNOR(a8, b8), AND(XNOR(a9, b9), AND(a10, NOT(b10))))))))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(XNOR(a7, b7), AND(XNOR(a8, b8), AND(XNOR(a9, b9), AND(XNOR(a10, b10), AND(a11, NOT(b11)))))))))))), \
    0))))))))))))
#define GT(a, b) GT_BITS(a, b)
/* Greater than or equal */
#define GE_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    OR(EQUAL_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11), GT_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11))
#define GE(a, b) GE_BITS(a, b)
/* Less than */
#define LT_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    GT_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)
#define LT(a, b) LT_BITS(a, b)
/* Less than or equal */
#define LE_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11)\
    GE_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)
#define LE(a, b) LE_BITS(a, b)
