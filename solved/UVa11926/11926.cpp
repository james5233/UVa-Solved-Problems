#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000000

int
main ()
{
	int N, M;
	while (scanf ("%d %d", &N, &M), N || M) {
		vector<int> v (MAXN + 1, 0);

		for (int n = 0; n < N; n++) {
			int st, end;
			scanf ("%d %d", &st, &end);

			for (int i = st; i < end; i++)
				v[i]++;
		}

		for (int m = 0; m < M; m++) {
			int st, end, rep;
			scanf ("%d %d %d", &st, &end, &rep);

			int lim_i = (MAXN - end) / rep;
			int D = end - st;
			int i;

			for (i = 0; i <= lim_i; i++) {
				int s = st + i*rep;
				int e = s + D;
				for (; s < e; s++)	
					v[s]++;
			}

			int s = st + i*rep;
			int e = MAXN;

			for (; s< e; s++)
				v[s]++;
		}
		
		int i;
		for (i = 0; i <= MAXN && v[i] < 2; i++);

		if (i > MAXN)
			printf ("NO CONFLICT\n");
		else
			printf ("CONFLICT\n");
	}

	return 0;
}
