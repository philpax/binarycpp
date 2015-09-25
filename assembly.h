#define EAX P(0)
#define ECX P(1)
#define EDX P(2)
#define EBX P(3)
#define ESP P(4)
#define EBP P(5)
#define ESI P(6)
#define EDI P(7)

#define MODRM(r1, r2, mod) \
	B(BOR(BOR(SHL(I(mod), P(6)), SHL(I(r2), P(3))), I(r1)))

#define NUMBER_TO_BYTES(x) \
	B(BAND(I(x), P(255))), B(SHR(I(x), P(8))), 0, 0

#define ADD_RR(r1, r2) 0x01, MODRM(I(r1), I(r2), P(3))

#define PUSH(r) B(ADD(P(80), I(r)))
#define POP(r) B(ADD(P(88), I(r)))
#define MOV_RR(r1, r2) 0x8B, MODRM(I(r2), I(r1), P(3))
#define MOV_RI(r, i) B(ADD(P(184), I(r))), NUMBER_TO_BYTES(I(i))

#define NOP() 0x90
#define RET() 0xC3