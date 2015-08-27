#include <stdio.h>
#include "tables.h"

/* The token pasting abuse that makes this possible */
#define JOIN_INTERNAL( a, b ) a##b
#define JOIN( a, b ) JOIN_INTERNAL( a, b )

/* Operators */
/* XOR */
#define XOR_00 0
#define XOR_10 1
#define XOR_01 1
#define XOR_11 0

#define XOR( a, b ) JOIN( XOR_, JOIN( a, b ) )

/* AND */
#define AND_00 0
#define AND_10 0
#define AND_01 0
#define AND_11 1

#define AND( a, b ) JOIN( AND_, JOIN( a, b ) )

/* Full adder macros */
/* Out = (A ^ B) ^ cin */
#define FULL_ADD_OUT( a, b, cin ) \
    XOR( XOR( a, b ), cin )

/* Carry_out = (A & B) ^ (Carry_in & (A ^ B)) */
/* The standard adder uses OR for the last 'gate' - this can safely be changed
   to XOR, which has been done here to avoid defining an OR operator */
#define FULL_ADD_CARRY( a, b, cin ) \
    XOR( AND( XOR( a, b ), cin ), AND( a, b ) )

/* Number -> binary conversion */
#define NUMBER_TO_BINARY( a ) JOIN( NUMBER_TO_BINARY_, a )

/* Binary -> number conversion */
#define BINARY_TO_NUMBER_INTERNAL( a, b, c, d ) \
    JOIN( BINARY_TO_NUMBER_, JOIN( a, JOIN( b, JOIN( c, d ) ) ) )

/* This is necessary to expand an incoming macro into its binary
   form; otherwise, only one argument will be passed into the macro
   expecting four */
#define BINARY_TO_NUMBER( x ) BINARY_TO_NUMBER_INTERNAL( x )

/* Four-bit addition! Can easily be extended, but gets messy for 
   obvious reasons */
#define ADD_A_B_4BIT( a1, a2, a3, a4, b1, b2, b3, b4 ) \
    FULL_ADD_OUT( a1, b1, \
        FULL_ADD_CARRY( a2, b2, \
            FULL_ADD_CARRY( a3, b3, \
                FULL_ADD_CARRY( a4, b4, 0 ) ) ) ), \
    \
    FULL_ADD_OUT( a2, b2, \
        FULL_ADD_CARRY( a3, b3, \
            FULL_ADD_CARRY( a4, b4, 0 ) ) ), \
    \
    FULL_ADD_OUT( a3, b3, \
        FULL_ADD_CARRY( a4, b4, 0 ) ), \
    \
    FULL_ADD_OUT( a4, b4, 0 ) \

/* This macro receives two NUMBER macros, which expand to the 4-bits necessary
   for each argument */
#define ADD_A_B_4BIT_NUMBERS( n1, n2 ) ADD_A_B_4BIT( n1, n2 )

int main()
{
    #define NUMBER_1 7
    #define NUMBER_2 4

    printf( "%i + %i = %i\n", 
        NUMBER_1,
        NUMBER_2,
        BINARY_TO_NUMBER( 
            ADD_A_B_4BIT_NUMBERS( 
                NUMBER_TO_BINARY( NUMBER_1 ), 
                NUMBER_TO_BINARY( NUMBER_2 ) ) ) );
}