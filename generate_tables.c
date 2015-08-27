#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	struct {
		unsigned char i : 4;
	} o;

	o.i = 0;
	while (1)
	{
		printf("#define BINARY_TO_NUMBER_%i%i%i%i %i\n", 
			(o.i >> 3) & 1,
			(o.i >> 2) & 1,
			(o.i >> 1) & 1,
			(o.i >> 0) & 1,
			o.i);

		printf("#define NUMBER_TO_BINARY_%i %i, %i, %i, %i\n",
			o.i,
			(o.i >> 3) & 1,
			(o.i >> 2) & 1,
			(o.i >> 1) & 1,
			(o.i >> 0) & 1);

		if (o.i == 15)
			break;
		o.i++;
	}
}