#include <bits/stdc++.h>

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		long N, sum;
		scanf ("%ld", &N);

		sum = 0L;
		while (N--) {
			long a, b;

			scanf ("%ld%*d%ld", &a, &b);
			sum += (a * b);
		}

		printf ("%ld\n", sum);
	}

	return 0;
}
