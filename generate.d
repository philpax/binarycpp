import std.stdio, std.conv, std.algorithm, std.range, std.math, std.string;

enum BitCount = 12;

auto toBitVector(int n)
{
	return iota(BitCount, 0, -1).map!(a => ((n >> (a-1)) & 1).to!string).array();
}

void writeSpace(ref File f)
{
	f.write("    ");
}

auto argumentRange(string s)
{
	return BitCount.iota.map!(a => "%s%s".format(s, a));
}

void generateNumber()
{
	auto f = File("number.h", "w");
	auto min = -1 << (BitCount - 1);
	auto max = -min;

	foreach (i; min..max)
	{
		f.writefln(`#define B_%s %s`, i.toBitVector.join(""), i);
		f.writefln(`#define %s_%s %s`, 
			(i < 0 ? "N" : "P"), abs(i), i.toBitVector.join(", "));
	}

	f.writeln(`/* Binary -> number conversion */`);
	f.writefln(`#define B_INTERNAL_(%s)\`, "a".argumentRange.join(", "));

	f.writeSpace();
	f.writef(`JOIN(B_, JOIN(%s`, "a".argumentRange[0..$-1].join(", JOIN("));
	f.writef(`, a%s`, BitCount-1);
	f.writeln(')'.repeat(BitCount));

	f.writeln(`#define B(x) B_INTERNAL_(x)`);

	/* Number -> binary conversion */
	f.writeln(`/* Number -> binary conversion */`);
	f.writeln(`#define P(n) JOIN(P_, n)`);
	f.writeln(`#define N(n) JOIN(N_, n)`);
}

void generateAddition(ref File f)
{
	f.writeln(`/* Addition */`);
	f.writefln(`#define ADD_BITS(%s)\`, 
		"a".argumentRange.chain("b".argumentRange).join(", "));
	foreach (i; 0..BitCount)
	{
		f.writeSpace();
		f.writefln(`FULL_ADD_OUT(a%s, b%s, \`, i, i);
		foreach (j; i+1..BitCount)
		{
			f.writeSpace();
			f.writef(` FULL_ADD_CARRY(a%s, b%s, `, j, j);
			if (j == BitCount-1)
				f.write(`0`);
			f.writeln(`\`);
		}
		f.writeSpace();
		f.writefln(` %s\`, ')'.repeat(BitCount-i-1));
		if (i == BitCount-1)
		{
			f.writeSpace();
			f.writeln(` 0\`);
		}
		f.writeSpace();
		f.write(')');
		f.writeln((i != BitCount - 1) ? `,\` : ``);
	}
	f.writeln(`#define ADD(a, b) ADD_BITS(a, b)`);
}

void generateNegation(ref File f)
{
	f.writeln(`/* Negation */`);
	f.writefln(`#define NEGATE_BITS(%s)\`, "a".argumentRange.join(", "));
	f.writeSpace();
	f.writeln(`ADD_BITS(\`);
	foreach (a; "a".argumentRange)
	{
		f.writeSpace();
		f.writefln(` NOT(%s),\`, a);
	}
	foreach (_; 0..BitCount-1)
	{
		f.writeSpace();
		f.writeln(` 0, \`);
	}
	f.writeSpace();
	f.writeln(` 1\`);
	f.writeSpace();
	f.writeln(`)`);
	f.writeln(`#define NEGATE(a) NEGATE_BITS(a)`);
}

void generateSubtraction(ref File f)
{
	f.writeln(`/* Subtraction */`);
	f.writefln(`#define SUB_BITS(%s)\`, 
		"a".argumentRange.chain("b".argumentRange).join(", "));
	f.writeSpace();
	f.writefln(`FE(ADD_BITS, %s, \`, "a".argumentRange.join(", "));
	f.writeSpace();
	f.writefln(` NEGATE_BITS(%s))`, "b".argumentRange.join(", "));
	f.writeln(`#define SUB(a, b) SUB_BITS(a, b)`);
}

void generateShiftLeft(ref File f)
{
	f.writeln(`/* Shift left */`);
	foreach (i; 0..BitCount+1)
	{
		f.writefln(`#define SHL_%s_BITS(%s)\`, i, "a".argumentRange.join(", "));
		f.writeSpace();
		f.writeln("a".argumentRange.drop(i).chain("0".repeat(i)).join(", "));
		f.writefln(`#define SHL_%s(a) SHL_%s_BITS(a)`, i, i);
	}
	f.writeln(`#define SHL(a, b) JOIN(JOIN(SHL_, B(I(b))), _BITS)(a)`);
}

void generateShiftRight(ref File f)
{
	f.writeln(`/* Shift right */`);
	foreach (i; 0..BitCount+1)
	{
		f.writefln(`#define SHR_%s_BITS(%s)\`, i, "a".argumentRange.join(", "));
		f.writeSpace();
		f.writeln("0".repeat(i).chain("a".argumentRange.take(BitCount-i)).join(", "));
		f.writefln(`#define SHR_%s(a) SHR_%s_BITS(a)`, i, i);
	}
	f.writeln(`#define SHR(a, b) JOIN(JOIN(SHR_, B(I(b))), _BITS)(a)`);
}

void generateExpansion(ref File f)
{
	f.writeln(`/* Expansion */`);
	f.writeln(`#define EXPAND(a) \`);
	f.writeSpace();
	f.writeln("a".repeat(BitCount).join(", "));
}

void generateBinaryAnd(ref File f)
{
	f.writeln(`/* Binary and */`);
	f.writefln(`#define BAND_BITS(%s)\`, 
		"a".argumentRange.chain("b".argumentRange).join(", "));
	f.writeSpace();
	f.writeln(BitCount.iota.map!(a => "AND(a%s, b%s)".format(a, a)).join(", "));
	f.writeln(`#define BAND(a, b) BAND_BITS(a, b)`);
}

void generateMultiplication(ref File f)
{
	f.writeln(`/* Multiplication */`);
	f.writefln(`#define MUL_BITS(%s)\`, 
		"a".argumentRange.chain("b".argumentRange).join(", "));
	foreach (i, a; "a".argumentRange.retro.enumerate)
	{
		f.writeSpace();
		f.writefln(`ADD(SHL(BAND(EXPAND(%s), I(%s)), P(%s)), \`, 
			a, "b".argumentRange.join(", "), i);
	}
	f.writeSpace();
	f.writeln(`P(0) \`);
	f.writeSpace();
	f.writeln(')'.repeat(BitCount));
	f.writeln(`#define MUL(a, b) MUL_BITS(a, b)`);
}

void generatePower(ref File f)
{
	f.writeln(`#define SQUARE(x) MUL(I(x), I(x))`);
	f.writeln(`#define CUBE(x) MUL(I(x), SQUARE(I(x)))`);
}

void generateEquality(ref File f)
{
	f.writeln(`/* Equality */`);
	f.writefln(`#define EQUAL_BITS(%s)\`, 
		"a".argumentRange.chain("b".argumentRange).join(", "));
	auto r = "a".argumentRange.zip("b".argumentRange);
	foreach (a, b; r)
	{
		f.writeSpace();
		f.writefln(`AND(XNOR(%s, %s), \`, a, b);
	}
	f.writeSpace();
	f.writefln("1%s", ')'.repeat(BitCount));
	f.writeln(`#define EQUAL(a, b) EQUAL_BITS(a, b)`);
}

void generateGreaterThan(ref File f)
{
	f.writeln(`/* Greater than */`);
	f.writefln(`#define GT_BITS(%s)\`,
		"a".argumentRange.chain("b".argumentRange).join(", "));
	auto r = "a".argumentRange.zip("b".argumentRange);

	f.writeSpace();
	f.writeln(`OR(AND(NOT(a0), b0), \`);
	foreach (i, a, b; r[1..$].enumerate)
	{
		f.writeSpace();
		f.write(`OR(`);
		if (i)
		{
			foreach (j; 0..i)
			{
				f.writef(`AND(XNOR(a%s, b%s), `, j+1, j+1);
			}
		}
		f.writef(`AND(%s, NOT(%s))`, a, b);
		if (i)
		{
			foreach (j; 0..i)
			{
				f.writef(`)`);
			}
		}
		f.writeln(`, \`);
	}

	f.writeSpace();
	f.writefln("0%s", ')'.repeat(BitCount));
	f.writeln(`#define GT(a, b) GT_BITS(a, b)`);
}

void generateGreaterThanOrEqual(ref File f)
{
	auto args = "a".argumentRange.chain("b".argumentRange).join(", ");
	f.writeln(`/* Greater than or equal */`);
	f.writefln(`#define GE_BITS(%s)\`, args);
	f.writeSpace();
	f.writefln(`OR(EQUAL_BITS(%s), GT_BITS(%s))`, args, args);
	f.writeln(`#define GE(a, b) GE_BITS(a, b)`);
}

void generateLogic()
{
	auto f = File("logic.h", "w");
	f.writeln(`#include "gates.h"`);
	f.writeln(`#include "number.h"`);
	f.generateAddition();
	f.generateNegation();
	f.generateSubtraction();
	f.generateShiftLeft();
	f.generateShiftRight();
	f.generateExpansion();
	f.generateBinaryAnd();
	f.generateMultiplication();
	f.generatePower();
	f.generateEquality();
	f.generateGreaterThan();
	f.generateGreaterThanOrEqual();
}

void main()
{
	generateNumber();
	generateLogic();
}