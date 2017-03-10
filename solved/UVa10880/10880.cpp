#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		long C, R, G, Q;
		long E;

		scanf ("%ld %ld", &C, &R);
		E = C - R;

		printf ("Case #%d:", t);

		if (R != C) {
			long lim_G = (long)sqrt (E) + 1L;

			vector<long> v;
			for (G = 1; G <= lim_G; G++) {
				Q = E / G;

				if (Q*G == E) {
					if (R < Q)
						v.push_back (Q);

					if (G != Q && R < G)
						v.push_back (G);
				}
			}	

			sort (v.begin (), v.end ());

			vector<long>::iterator it;
			long old = -1;
			for (it = v.begin (); it != v.end (); it++) {
				if (old != *it)
					printf (" %ld", *it);
				old = *it;
			}

			printf ("\n");
		} else if (R == C)
			printf (" 0\n");
	}

	return 0;
}
