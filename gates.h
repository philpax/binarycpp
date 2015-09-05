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

/* OR */
#define OR_00 0
#define OR_10 1
#define OR_01 1
#define OR_11 1

#define OR(a, b) JOIN(OR_, JOIN(a, b))

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

/* XNOR */
#define XNOR(a, b) NOT(XOR(a, b))

/* Full adder macros */
/* Out = (A ^ B) ^ cin */
#define FULL_ADD_OUT(a, b, cin) \
    XOR(XOR(a, b), cin)

/* Carry_out = (A & B) ^ (Carry_in & (A ^ B)) */
/* The standard adder uses OR for the last 'gate' - this can safely be changed
   to XOR, which has been done here to avoid defining an OR operator */
#define FULL_ADD_CARRY(a, b, cin) \
    XOR(AND(XOR(a, b), cin), AND(a, b))

/* Identity gate to allow passing a bitvector through as one argument */
#define I(...) __VA_ARGS__

/* Force expansion call */
#define FE(fn, ...) fn(__VA_ARGS__)

/* If */
#define IF_0(x)
#define IF_1(x) x
#define IF(cond, x) JOIN(IF_, cond)(x)

/* If-else */
#define IF_ELSE_0(x, y) y
#define IF_ELSE_1(x, y) x
#define IF_ELSE(cond, x, y) JOIN(IF_ELSE_, cond)(x, y)