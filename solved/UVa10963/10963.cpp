#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N;
		scanf ("%d", &N);
		int mx, mn;

		mx = INT_MIN;
		mn = INT_MAX;

		while (N--) {
			int hi, lo, w;
			scanf ("%d%d", &hi, &lo);

			w = hi - lo;
			mx = max (mx, w);
			mn = min (mn, w);
		}

		if (mx == mn)
			printf ("yes\n");
		else
			printf ("no\n");

		if (T)
			printf ("\n");
	}

	return 0;
}
