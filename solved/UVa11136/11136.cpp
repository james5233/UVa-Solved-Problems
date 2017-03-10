#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	while (scanf ("%d", &N), N) {
		multiset<int> urn;
		long cost = 0L;

		for (int i = 0; i < N; i++) {
			int K;
			scanf ("%d", &K);

			for (int k = 0; k < K; k++) {
				int bill;
				scanf ("%d", &bill);

				urn.insert (bill);
			}
			
			multiset<int>::iterator it_lo, it_hi;
			it_lo = urn.begin ();
			it_hi = urn.end();
			it_hi--;

			cost += (*it_hi - *it_lo);
			urn.erase (it_lo);
			urn.erase (it_hi);
		}

		printf ("%ld\n", cost);
	}

	return 0;
}

