#include "gates.h"
#include "number.h"
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
