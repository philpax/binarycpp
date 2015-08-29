#include <stdio.h>
#include <stdlib.h>

const int BitCount = 12;

void generateTables()
{
	int min = -1 << (BitCount-1);
	int max = ~min + 1;

	int i = min;
	while (i != max)
	{
		int j = BitCount;

		printf("#define B_");
		while (j --> 0)
			printf("%i", (i >> j) & 1);
		printf(" %i\n", i);

		printf("#define %s_%i ", (i < 0 ? "N" : "P"), abs(i));
		j = BitCount;
		while (j --> 0)
			printf("%s%i", (j == BitCount - 1) ? "" : ", ", (i >> j) & 1);
		printf("\n");

		i++;
	}
}

void writeJoin(int i)
{
	printf("JOIN(a%i, ", i);
	if (i == BitCount - 2)
		printf("a%i", BitCount - 1);
	else
		writeJoin(i+1);
	printf(")");
}

void generateBInternal()
{
	int i;

	/* Macro declaration */
	printf("/* Binary -> number conversion */\n");
	printf("#define B_INTERNAL_(");

	for (i = 0; i < BitCount; ++i)
	{
		if (i)
			printf(", ");

		printf("a%i", i);
	}

	printf(")\\\n");

	/* Statement */
	printf("    JOIN(B_, ");
	writeJoin(0);
	printf(")\n");

	printf("#define B_(x) B_INTERNAL_(x)\n");
}

void generateAdder()
{
	int i;

	/* Macro declaration */
	printf("/* Addition */\n");
	printf("#define ADD_BITS(");

	for (i = 0; i < BitCount; ++i)
	{
		if (i)
			printf(", ");

		printf("a%i", i);
	}

	for (i = 0; i < BitCount; ++i)
	{
		printf(", b%i", i);
	}

	printf(")\\\n");

	/* Statements */
	for (i = 0; i < BitCount; ++i)
	{
		int j;
		printf("    FULL_ADD_OUT(a%i, b%i, \\\n", i, i);
		for (j = i + 1; j < BitCount; ++j)
		{
			printf("     FULL_ADD_CARRY(a%i, b%i, ", j, j);
			if (j == BitCount - 1)
				printf("0");
			printf("\\\n");
		}

		printf("     ");
		for (j = i + 1; j < BitCount; ++j)
			printf(")");

		printf("\\\n");

		if (i == BitCount - 1)
			printf("     0\\\n");

		printf("    )%s\n", (i < BitCount - 1 ? ",\\" : ""));
	}

	printf("#define ADD(a, b) ADD_BITS(a, b)\n");
}

void generateNegate()
{
	int i;

	/* Macro declaration */
	printf("/* Negation */\n");
	printf("#define NEGATE_BITS(");

	for (i = 0; i < BitCount; ++i)
	{
		if (i)
			printf(", ");

		printf("a%i", i);
	}

	printf(")\\\n");

	/* Statements */
	printf("    ADD_BITS(\\\n");
	for (i = 0; i < BitCount; ++i)
		printf("     NOT(a%i),\\\n", i);
	for (i = 0; i < BitCount; ++i)
		printf("     %i%s\\\n", i == BitCount - 1, (i != BitCount - 1) ? ", " : "");
	printf("    )\n");
	printf("#define NEGATE(a) NEGATE_BITS(a)\n");
}

int main()
{
	generateTables();
	generateBInternal();
	generateAdder();
	generateNegate();
}