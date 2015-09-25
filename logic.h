#include "gates.h"
#include "number.h"
#include "control_flow.h"
/* Addition */
#define ADD_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
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
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     )))))))))))))))\
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
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     ))))))))))))))\
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
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     )))))))))))))\
    ),\
    FULL_ADD_OUT(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     ))))))))))))\
    ),\
    FULL_ADD_OUT(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     )))))))))))\
    ),\
    FULL_ADD_OUT(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     ))))))))))\
    ),\
    FULL_ADD_OUT(a6, b6, \
     FULL_ADD_CARRY(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     )))))))))\
    ),\
    FULL_ADD_OUT(a7, b7, \
     FULL_ADD_CARRY(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     ))))))))\
    ),\
    FULL_ADD_OUT(a8, b8, \
     FULL_ADD_CARRY(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     )))))))\
    ),\
    FULL_ADD_OUT(a9, b9, \
     FULL_ADD_CARRY(a10, b10, \
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     ))))))\
    ),\
    FULL_ADD_OUT(a10, b10, \
     FULL_ADD_CARRY(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     )))))\
    ),\
    FULL_ADD_OUT(a11, b11, \
     FULL_ADD_CARRY(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     ))))\
    ),\
    FULL_ADD_OUT(a12, b12, \
     FULL_ADD_CARRY(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     )))\
    ),\
    FULL_ADD_OUT(a13, b13, \
     FULL_ADD_CARRY(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     ))\
    ),\
    FULL_ADD_OUT(a14, b14, \
     FULL_ADD_CARRY(a15, b15, 0\
     )\
    ),\
    FULL_ADD_OUT(a15, b15, \
     \
     0\
    )
#define ADD(a, b) ADD_BITS(a, b)
/* Negation */
#define NEGATE_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
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
     NOT(a12),\
     NOT(a13),\
     NOT(a14),\
     NOT(a15),\
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
     0, \
     0, \
     0, \
     0, \
     1\
    )
#define NEGATE(a) NEGATE_BITS(a)
/* Subtraction */
#define SUB_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
    FE(ADD_BITS, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, \
     NEGATE_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15))
#define SUB(a, b) SUB_BITS(a, b)
/* Shift left */
#define SHL_0_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
#define SHL_0(a) SHL_0_BITS(a)
#define SHL_1_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 0
#define SHL_1(a) SHL_1_BITS(a)
#define SHL_2_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 0, 0
#define SHL_2(a) SHL_2_BITS(a)
#define SHL_3_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 0, 0, 0
#define SHL_3(a) SHL_3_BITS(a)
#define SHL_4_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 0, 0, 0, 0
#define SHL_4(a) SHL_4_BITS(a)
#define SHL_5_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 0, 0, 0, 0, 0
#define SHL_5(a) SHL_5_BITS(a)
#define SHL_6_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, 0, 0, 0, 0, 0, 0
#define SHL_6(a) SHL_6_BITS(a)
#define SHL_7_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a7, a8, a9, a10, a11, a12, a13, a14, a15, 0, 0, 0, 0, 0, 0, 0
#define SHL_7(a) SHL_7_BITS(a)
#define SHL_8_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a8, a9, a10, a11, a12, a13, a14, a15, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_8(a) SHL_8_BITS(a)
#define SHL_9_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a9, a10, a11, a12, a13, a14, a15, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_9(a) SHL_9_BITS(a)
#define SHL_10_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a10, a11, a12, a13, a14, a15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_10(a) SHL_10_BITS(a)
#define SHL_11_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a11, a12, a13, a14, a15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_11(a) SHL_11_BITS(a)
#define SHL_12_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a12, a13, a14, a15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_12(a) SHL_12_BITS(a)
#define SHL_13_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a13, a14, a15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_13(a) SHL_13_BITS(a)
#define SHL_14_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a14, a15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_14(a) SHL_14_BITS(a)
#define SHL_15_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_15(a) SHL_15_BITS(a)
#define SHL_16_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHL_16(a) SHL_16_BITS(a)
#define SHL(a, b) JOIN(JOIN(SHL_, B(I(b))), _BITS)(a)
/* Shift right */
#define SHR_0_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15
#define SHR_0(a) SHR_0_BITS(a)
#define SHR_1_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
#define SHR_1(a) SHR_1_BITS(a)
#define SHR_2_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
#define SHR_2(a) SHR_2_BITS(a)
#define SHR_3_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
#define SHR_3(a) SHR_3_BITS(a)
#define SHR_4_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
#define SHR_4(a) SHR_4_BITS(a)
#define SHR_5_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
#define SHR_5(a) SHR_5_BITS(a)
#define SHR_6_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
#define SHR_6(a) SHR_6_BITS(a)
#define SHR_7_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, a0, a1, a2, a3, a4, a5, a6, a7, a8
#define SHR_7(a) SHR_7_BITS(a)
#define SHR_8_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, a0, a1, a2, a3, a4, a5, a6, a7
#define SHR_8(a) SHR_8_BITS(a)
#define SHR_9_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, a0, a1, a2, a3, a4, a5, a6
#define SHR_9(a) SHR_9_BITS(a)
#define SHR_10_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, a0, a1, a2, a3, a4, a5
#define SHR_10(a) SHR_10_BITS(a)
#define SHR_11_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, a0, a1, a2, a3, a4
#define SHR_11(a) SHR_11_BITS(a)
#define SHR_12_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, a0, a1, a2, a3
#define SHR_12(a) SHR_12_BITS(a)
#define SHR_13_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, a0, a1, a2
#define SHR_13(a) SHR_13_BITS(a)
#define SHR_14_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, a0, a1
#define SHR_14(a) SHR_14_BITS(a)
#define SHR_15_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, a0
#define SHR_15(a) SHR_15_BITS(a)
#define SHR_16_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)\
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define SHR_16(a) SHR_16_BITS(a)
#define SHR(a, b) JOIN(JOIN(SHR_, B(I(b))), _BITS)(a)
/* Expansion */
#define EXPAND(a) \
    a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a
/* Binary and */
#define BAND_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
    AND(a0, b0), AND(a1, b1), AND(a2, b2), AND(a3, b3), AND(a4, b4), AND(a5, b5), AND(a6, b6), AND(a7, b7), AND(a8, b8), AND(a9, b9), AND(a10, b10), AND(a11, b11), AND(a12, b12), AND(a13, b13), AND(a14, b14), AND(a15, b15)
#define BAND(a, b) BAND_BITS(a, b)
/* Binary or */
#define BOR_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
    OR(a0, b0), OR(a1, b1), OR(a2, b2), OR(a3, b3), OR(a4, b4), OR(a5, b5), OR(a6, b6), OR(a7, b7), OR(a8, b8), OR(a9, b9), OR(a10, b10), OR(a11, b11), OR(a12, b12), OR(a13, b13), OR(a14, b14), OR(a15, b15)
#define BOR(a, b) BOR_BITS(a, b)
/* Multiplication */
#define MUL_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
    ADD(SHL(BAND(EXPAND(a15), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(0)), \
    ADD(SHL(BAND(EXPAND(a14), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(1)), \
    ADD(SHL(BAND(EXPAND(a13), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(2)), \
    ADD(SHL(BAND(EXPAND(a12), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(3)), \
    ADD(SHL(BAND(EXPAND(a11), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(4)), \
    ADD(SHL(BAND(EXPAND(a10), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(5)), \
    ADD(SHL(BAND(EXPAND(a9), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(6)), \
    ADD(SHL(BAND(EXPAND(a8), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(7)), \
    ADD(SHL(BAND(EXPAND(a7), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(8)), \
    ADD(SHL(BAND(EXPAND(a6), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(9)), \
    ADD(SHL(BAND(EXPAND(a5), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(10)), \
    ADD(SHL(BAND(EXPAND(a4), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(11)), \
    ADD(SHL(BAND(EXPAND(a3), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(12)), \
    ADD(SHL(BAND(EXPAND(a2), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(13)), \
    ADD(SHL(BAND(EXPAND(a1), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(14)), \
    ADD(SHL(BAND(EXPAND(a0), I(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)), P(15)), \
    P(0) \
    ))))))))))))))))
#define MUL(a, b) MUL_BITS(a, b)
#define SQUARE(x) MUL(I(x), I(x))
#define CUBE(x) MUL(I(x), SQUARE(I(x)))
/* Equality */
#define EQUAL_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
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
    AND(XNOR(a12, b12), \
    AND(XNOR(a13, b13), \
    AND(XNOR(a14, b14), \
    AND(XNOR(a15, b15), \
    1))))))))))))))))
#define EQUAL(a, b) EQUAL_BITS(a, b)
/* Greater than */
#define GT_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
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
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(XNOR(a7, b7), AND(XNOR(a8, b8), AND(XNOR(a9, b9), AND(XNOR(a10, b10), AND(XNOR(a11, b11), AND(a12, NOT(b12))))))))))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(XNOR(a7, b7), AND(XNOR(a8, b8), AND(XNOR(a9, b9), AND(XNOR(a10, b10), AND(XNOR(a11, b11), AND(XNOR(a12, b12), AND(a13, NOT(b13)))))))))))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(XNOR(a7, b7), AND(XNOR(a8, b8), AND(XNOR(a9, b9), AND(XNOR(a10, b10), AND(XNOR(a11, b11), AND(XNOR(a12, b12), AND(XNOR(a13, b13), AND(a14, NOT(b14))))))))))))))), \
    OR(AND(XNOR(a1, b1), AND(XNOR(a2, b2), AND(XNOR(a3, b3), AND(XNOR(a4, b4), AND(XNOR(a5, b5), AND(XNOR(a6, b6), AND(XNOR(a7, b7), AND(XNOR(a8, b8), AND(XNOR(a9, b9), AND(XNOR(a10, b10), AND(XNOR(a11, b11), AND(XNOR(a12, b12), AND(XNOR(a13, b13), AND(XNOR(a14, b14), AND(a15, NOT(b15)))))))))))))))), \
    0))))))))))))))))
#define GT(a, b) GT_BITS(a, b)
/* Greater than or equal */
#define GE_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
    OR(EQUAL_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15), GT_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15))
#define GE(a, b) GE_BITS(a, b)
/* Less than */
#define LT_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
    GT_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)
#define LT(a, b) LT_BITS(a, b)
/* Less than or equal */
#define LE_BITS(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15)\
    GE_BITS(b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14, b15, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15)
#define LE(a, b) LE_BITS(a, b)
