#include <bits/stdc++.h>
using namespace std;

#define INFTY 50000

int
main ()
{
	int T;
	scanf ("%d", &T);

	for (int t = 1; t <= T; t++) {
		deque<int> solved[3];
		int ct[3];
		int tot = 0;

		for (int i = 0; i < 3; i++) {
			int N;
			scanf ("%d", &N);

			tot += N;
			for (int j = 0; j < N; j++) {
				int prob;
				scanf ("%d", &prob);

				solved[i].push_back (prob);
			}
			
			solved[i].push_back (INFTY);
			sort (solved[i].begin (), solved[i].end ());
		}
		
		int ind[3];
		ind[0] = ind[1] = ind[2] = 0;
		ct[0] = ct[1] = ct[2] = 0;

		for (int j = 0; j < tot; ) {
			int fr[3], h[3], i, n_h;

			h[0] = h[1] = h[2] = 0;
			n_h = 0;

			for (i = 0; i < 3; i++)
				fr[i] = solved[i][ind[i]];
			
			int m = min (min (fr[0], fr[1]), fr[2]);

			for (i = 0; i < 3; i++) {
				if (m == fr[i]) {
					h[i] = 1;
					n_h++;
				}
			}

			if (n_h == 1) {
				for (int i = 0; i < 3; i++) {
					if (h[i] == 1) {
						ind[i]++;
						ct[i]++;
						j++;
					}
				}
			} else {
				for (int i = 0; i < 3; i++)
					if (h[i] == 1) {
						solved[i].erase (solved[i].begin() + ind[i]);
						j++;
					}
			}
		}

		solved[0].pop_back ();
		solved[1].pop_back ();
		solved[2].pop_back ();
		
		int mx = max (max (ct[0], ct[1]), ct[2]);

		printf ("Case #%d:\n", t);
		for (int i = 0; i < 3; i++) {
			if (ct[i] == mx) {
				printf ("%d %d", i + 1, ct[i]);
				deque<int>::iterator it;
				for (it = solved[i].begin (); it != solved[i].end (); it++)
					printf (" %d", *it);
				printf ("\n");
			}
		}
	}

	return 0;
}

