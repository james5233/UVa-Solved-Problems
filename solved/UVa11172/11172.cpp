#include <bits/stdc++.h>

int
main ()
{
	long T;
	for (scanf ("%ld", &T); T--;) {
		long a, b;
		scanf ("%ld%ld", &a, &b);

		if (a < b)
			printf ("<\n");
		else if (a > b)
			printf (">\n");
		else
			printf ("=\n");
	}
	
	return 0;
}
