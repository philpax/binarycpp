/* The token pasting abuse that makes this possible */
#define JOIN_INTERNAL(a, b) a##b
#define JOIN(a, b) JOIN_INTERNAL(a, b)

/* Operators */
/* XOR */
#define XOR_00 0
#define XOR_10 1
#define XOR_01 1
#define XOR_11 0

#define XOR(a, b) JOIN(XOR_, JOIN(a, b))

/* AND */
#define AND_00 0
#define AND_10 0
#define AND_01 0
#define AND_11 1

#define AND(a, b) JOIN(AND_, JOIN(a, b))

/* NOT */
#define NOT_0 1
#define NOT_1 0

#define NOT(a) JOIN(NOT_, a)

/* Full adder macros */
/* Out = (A ^ B) ^ cin */
#define FULL_ADD_OUT(a, b, cin) \
    XOR(XOR(a, b), cin)

/* Carry_out = (A & B) ^ (Carry_in & (A ^ B)) */
/* The standard adder uses OR for the last 'gate' - this can safely be changed
   to XOR, which has been done here to avoid defining an OR operator */
#define FULL_ADD_CARRY(a, b, cin) \
    XOR(AND(XOR(a, b), cin), AND(a, b))
