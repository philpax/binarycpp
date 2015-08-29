#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
	int8_t i = CHAR_MIN;
	while (1)
	{
		printf("#define B_%i%i%i%i%i%i%i%i\t%i\n",
			(i >> 7) & 1,
			(i >> 6) & 1,
			(i >> 5) & 1,
			(i >> 4) & 1,
			(i >> 3) & 1,
			(i >> 2) & 1,
			(i >> 1) & 1,
			(i >> 0) & 1,
			i);

		printf("#define %s_%i\t%i, %i, %i, %i, %i, %i, %i, %i\n",
			(i < 0 ? "N" : "P"),
			abs(i),
			(i >> 7) & 1,
			(i >> 6) & 1,
			(i >> 5) & 1,
			(i >> 4) & 1,
			(i >> 3) & 1,
			(i >> 2) & 1,
			(i >> 1) & 1,
			(i >> 0) & 1);

		if (i == CHAR_MAX)
			break;
		i++;
	}
}