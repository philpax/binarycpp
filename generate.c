#include <stdio.h>
#include <stdlib.h>

const int BitCount = 12;

void writeJoin(FILE* file, int i)
{
	fprintf(file, "JOIN(a%i, ", i);
	if (i == BitCount - 2)
		fprintf(file, "a%i", BitCount - 1);
	else
		writeJoin(file, i+1);
	fprintf(file, ")");
}

void generateNumber()
{
	FILE* file = fopen("number.h", "w");
	if (!file)
		return;

	int min = -1 << (BitCount-1);
	int max = -min;

	int i = min;
	while (i != max)
	{
		int j = BitCount;

		fprintf(file, "#define B_");
		while (j --> 0)
			fprintf(file, "%i", (i >> j) & 1);
		fprintf(file, " %i\n", i);

		fprintf(file, "#define %s_%i ", (i < 0 ? "N" : "P"), abs(i));
		j = BitCount;
		while (j --> 0)
			fprintf(file, "%s%i", (j == BitCount - 1) ? "" : ", ", (i >> j) & 1);
		fprintf(file, "\n");

		i++;
	}

	/* Binary -> number conversion */
	fprintf(file, "/* Binary -> number conversion */\n");
	fprintf(file, "#define B_INTERNAL_(");

	for (i = 0; i < BitCount; ++i)
	{
		if (i)
			fprintf(file, ", ");

		fprintf(file, "a%i", i);
	}

	fprintf(file, ")\\\n");

	/* Statement */
	fprintf(file, "    JOIN(B_, ");
	writeJoin(file, 0);
	fprintf(file, ")\n");

	fprintf(file, "#define B(x) B_INTERNAL_(x)\n");

	/* Number -> binary conversion */
	fprintf(file, "/* Number -> binary conversion */\n");
	fprintf(file, "#define P(n) JOIN(P_, n)\n");
	fprintf(file, "#define N(n) JOIN(N_, n)\n");

	fclose(file);
}

void generateLogic()
{
	FILE* file = fopen("logic.h", "w");
	int i;

	if (!file)
		return;

	fprintf(file, "#include \"gates.h\"\n");
	fprintf(file, "#include \"number.h\"\n");

	/* Addition */
	/* Macro declaration */
	fprintf(file, "/* Addition */\n");
	fprintf(file, "#define ADD_BITS(");

	for (i = 0; i < BitCount; ++i)
	{
		if (i)
			fprintf(file, ", ");

		fprintf(file, "a%i", i);
	}

	for (i = 0; i < BitCount; ++i)
	{
		fprintf(file, ", b%i", i);
	}

	fprintf(file, ")\\\n");

	/* Statements */
	for (i = 0; i < BitCount; ++i)
	{
		int j;
		fprintf(file, "    FULL_ADD_OUT(a%i, b%i, \\\n", i, i);
		for (j = i + 1; j < BitCount; ++j)
		{
			fprintf(file, "     FULL_ADD_CARRY(a%i, b%i, ", j, j);
			if (j == BitCount - 1)
				fprintf(file, "0");
			fprintf(file, "\\\n");
		}

		fprintf(file, "     ");
		for (j = i + 1; j < BitCount; ++j)
			fprintf(file, ")");

		fprintf(file, "\\\n");

		if (i == BitCount - 1)
			fprintf(file, "     0\\\n");

		fprintf(file, "    )%s\n", (i < BitCount - 1 ? ",\\" : ""));
	}

	fprintf(file, "#define ADD(a, b) ADD_BITS(a, b)\n");

	/* Negation */
	/* Macro declaration */
	fprintf(file, "/* Negation */\n");
	fprintf(file, "#define NEGATE_BITS(");

	for (i = 0; i < BitCount; ++i)
	{
		if (i)
			fprintf(file, ", ");

		fprintf(file, "a%i", i);
	}

	fprintf(file, ")\\\n");

	/* Statements */
	fprintf(file, "    ADD_BITS(\\\n");
	for (i = 0; i < BitCount; ++i)
		fprintf(file, "     NOT(a%i),\\\n", i);
	for (i = 0; i < BitCount; ++i)
		fprintf(file, "     %i%s\\\n", i == BitCount - 1, (i != BitCount - 1) ? ", " : "");
	fprintf(file, "    )\n");
	fprintf(file, "#define NEGATE(a) NEGATE_BITS(a)\n");

	/* Subtraction */
	/* Macro declaration */
	fprintf(file, "/* Subtraction */\n");
	fprintf(file, "#define SUB_BITS(");

	for (i = 0; i < BitCount; ++i)
	{
		if (i)
			fprintf(file, ", ");

		fprintf(file, "a%i", i);
	}

	for (i = 0; i < BitCount; ++i)
	{
		fprintf(file, ", b%i", i);
	}

	fprintf(file, ")\\\n");
	fprintf(file, "    FE(ADD_BITS, ");
	for (i = 0; i < BitCount; ++i)
		fprintf(file, "a%i, ", i);
	fprintf(file, "\\\n");
	fprintf(file, "     NEGATE_BITS(");
	for (i = 0; i < BitCount; ++i)
		fprintf(file, "b%i%s", i, (i != BitCount - 1) ? ", " : "");
	fprintf(file, "))\n");

	fprintf(file, "#define SUB(a, b) SUB_BITS(a, b)\n");

	/* Shift left */
	fprintf(file, "/* Shift left */\n");
	for (i = 1; i < BitCount+1; ++i)
	{
		int j = 0;
		fprintf(file, "#define SHL_%i_BITS(", i);

		for (j = 0; j < BitCount; ++j)
		{
			if (j)
				fprintf(file, ", ");

			fprintf(file, "a%i", j);
		}

		fprintf(file, ")\\\n");

		fprintf(file, "    ");
		for (j = i; j < BitCount; ++j)
			fprintf(file, "a%i, ", j);
		for (j = 0; j < i; ++j)
			fprintf(file, "0%s", (j != i-1) ? ", " : "");
		fprintf(file, "\n");

		fprintf(file, "#define SHL_%i(a) SHL_%i_BITS(a)\n", j, j);
	}
	fprintf(file, "#define SHL(a, b) JOIN(JOIN(SHL_, B(I(b))), _BITS)(a)\n");

	fclose(file);
}

int main()
{
	generateNumber();
	generateLogic();
}