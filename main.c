#include <complex.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X_MIN (-2)
#define X_MAX (0.58)
#define Y_MIN (0)
#define Y_MAX (1.20)

long double complex iterate(long double complex z, long double complex c)
{
	return z*z + c;
}

/* Determines whether a given complex number is contained within the partial
 * Mandelbrot set of a given threshold. */
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

/* Returns a random number from a uniform distribution.
 *
 * NOTE: Before calling this function, make sure to initialize the PRNG by
 * calling `srandom(time(NULL))`. */
long double uniform(long double a, long double b)
{
	long double r = (long double) random() / (long double) RAND_MAX;
	return a + (b - a) * r;
}

int main()
{
	return 0;
}
