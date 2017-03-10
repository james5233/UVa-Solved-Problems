#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

int
main ()
{
	long N, c;

	while (scanf ("%ld%ld", &N, &c), N || c) {
		long mid, b, l, d, q;

		mid = (N + 1) / 2;

		if (c == 1)
			printf ("Line = %ld, column = %ld.\n", mid, mid);
		else {
			c--;
			b = sqrt (1.0 * c);
			b -= !(b & 1L);
			l = b + 1;
			b += 2;

			d = (b * b - 1L) - c;
			q = d / l;

			D( printf ("DEBUG: mid = %ld, b = %ld, d = %ld, "
			"l = %ld, q = %ld\n", mid, b, d, l, q); )

			if (q == 0)
				printf ("Line = %ld, column = %ld.\n", mid + b/2 - d%l, mid + b/2);
			else if (q == 1)
				printf ("Line = %ld, column = %ld.\n", mid - b/2, mid + b/2 - d%l);
			else if (q == 2)
				printf ("Line = %ld, column = %ld.\n", mid - b/2 + d%l, mid - b/2);
			else
				printf ("Line = %ld, column = %ld.\n", mid + b/2, mid - b/2 + d%l);
		}
	}

	return 0;
}
