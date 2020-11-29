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

/* Runs a Montecarlo integration on the partial Mandelbrot set with a finite
 * threshold. The variable `samples` determines how many points will be
 * checked. */
void integrate(unsigned int threshold, unsigned int samples)
{
	srandom(time(NULL));
	unsigned int hits = 0;
	for (unsigned int i = 0; i < samples; i++) {
		long double x = uniform(X_MIN, X_MAX);
		long double y = uniform(Y_MIN, Y_MAX);
		long double complex c = x + I * y;

		if (is_mandelbrot(c, threshold))
			hits++;
	}

	long double rect_area = (X_MAX - X_MIN) * (Y_MAX - Y_MIN);
	long double q = (long double) hits / (long double) samples;
	long double A = q * rect_area;
	long double u_A = rect_area * sqrtl(hits * (1 - q)) / samples;

	printf("threshold = %u\tA = %Lf +/- %Lf\n", threshold, 2*A, 2*u_A);
}

int main()
{
	return 0;
}
