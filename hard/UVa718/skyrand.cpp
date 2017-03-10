#include <bits/stdc++.h>

#define FMAX 50000000L
#define EMAX 100L

int main (int argc, char *argv[])
{
	long F, E, A, B;
	int T;

	if (argc > 1)
		T = atoi (argv[1]);

	printf ("%d\n", T);
	srandom ((unsigned int)time(NULL));
	while (T--) {

		F = 1L + (random () % (FMAX - 1L));
		E = 1L + (random () % (EMAX - 1L));
		A = random () % F;
		B = random () % F;

		printf ("%ld %ld %ld %ld\n", F, E, A, B);
		for (long i = 0; i < E; i++) {
			long st, end;
			st = 1L + (random ()% 30);
			end = random () % F;
			printf ("%ld %ld\n", st, end);
		}
	}
	
	return 0;
}
