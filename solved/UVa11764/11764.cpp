#include <bits/stdc++.h>

int
main ()
{
	int t, T;
	for (scanf ("%d", &T), t = 1; t <= T; t++) {
		int N;
		scanf ("%d", &N);

		int prev;
		int n_high, n_low;

		n_high = n_low = 0;
		scanf ("%d", &prev);

		for (int n = 1; n < N; n++) {
			int cur;
			scanf ("%d", &cur);

			if (cur > prev)
				n_high++;
			else if (cur < prev)
				n_low++;

			prev = cur;
		}

		printf ("Case %d: %d %d\n", t, n_high, n_low);
	}

	return 0;
}
