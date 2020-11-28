#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long double complex iterate(long double complex z, long double complex c)
{
	return z*z + c;
}

bool is_mandelbrot(long double complex c, unsigned int threshold)
{
	long double complex z = 0;
	for (unsigned int i = 0; i < threshold; i++) {
		z = iterate(z, c);

		if (cabsl(z) > 2)
			return false;
	}

	return true;
}

int main()
{
	return 0;
}
