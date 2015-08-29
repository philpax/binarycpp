#include <stdio.h>

const int BitCount = 8;

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
	printf("#define ADD_%iBIT(", BitCount);

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
}

int main()
{
	generateBInternal();
	generateAdder();		
}