#include <bits/stdc++.h>

#define MAXM 110

int
main ()
{
	int M, N;
	double dwn, pr;

	while (scanf ("%d%lf%lf%d", &M, &dwn, &pr, &N), (M > 0)) {
		int m, n;
		double rate[MAXM];
		int month[MAXM];

		for (n = 0; n < N; n++)
			scanf ("%d%lf", month + n, rate + n);
		
		double cur, rem;
		double rt, inst; 
		
		rt = rate[0];
		inst = pr / M;

		cur = (pr + dwn) * (1.0 - rate[0]);
		rem = pr;
		m = n = 1;

		while (cur <= rem) {
			if (m >= month[n] && n < N) {
				rt = rate[n];
				n++;
			}

			cur = cur * (1.0 - rt);
			rem -= inst;

			m++;
		}

		printf ("%d month%s", m - 1, (m - 1) == 1 ? "\n" : "s\n");
	}

	return 0;
}
