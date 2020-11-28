#include <complex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double complex iterate(double complex z, double complex c)
{
	return z*z + c;
}

bool is_mandelbrot(double complex c, unsigned int threshold)
{
	double complex z = 0;
	for (unsigned int i = 0; i < threshold; i++) {
		z = iterate(z, c);

		if (cabs(z) > 2)
			return false;
	}

	return true;
}

int main()
{
	return 0;
}
