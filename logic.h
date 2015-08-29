/* Binary -> number conversion */
#define B_INTERNAL_(a0, a1, a2, a3, a4, a5, a6, a7)\
    JOIN(B_, JOIN(a0, JOIN(a1, JOIN(a2, JOIN(a3, JOIN(a4, JOIN(a5, JOIN(a6, a7))))))))
#define B_(x) B_INTERNAL_(x)
/* Addition */
#define ADD_8BIT(a0, a1, a2, a3, a4, a5, a6, a7, b0, b1, b2, b3, b4, b5, b6, b7)\
    FULL_ADD_OUT(a0, b0, \
     FULL_ADD_CARRY(a1, b1, \
     FULL_ADD_CARRY(a2, b2, \
     FULL_ADD_CARRY(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, 0\
     )))))))\
    ),\
    FULL_ADD_OUT(a1, b1, \
     FULL_ADD_CARRY(a2, b2, \
     FULL_ADD_CARRY(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, 0\
     ))))))\
    ),\
    FULL_ADD_OUT(a2, b2, \
     FULL_ADD_CARRY(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, 0\
     )))))\
    ),\
    FULL_ADD_OUT(a3, b3, \
     FULL_ADD_CARRY(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, 0\
     ))))\
    ),\
    FULL_ADD_OUT(a4, b4, \
     FULL_ADD_CARRY(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, 0\
     )))\
    ),\
    FULL_ADD_OUT(a5, b5, \
     FULL_ADD_CARRY(a6, b6, \
     FULL_ADD_CARRY(a7, b7, 0\
     ))\
    ),\
    FULL_ADD_OUT(a6, b6, \
     FULL_ADD_CARRY(a7, b7, 0\
     )\
    ),\
    FULL_ADD_OUT(a7, b7, \
     \
     0\
    )
