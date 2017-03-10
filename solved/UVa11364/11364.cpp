#include <bits/stdc++.h>

#define MAXN 30
int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N;
		int store[MAXN];

		scanf ("%d", &N);
		for (int i = 0; i < N; i++)
			scanf ("%d", store + i);

		if (N <= 1) {
			printf ("0\n");
			continue;
		}
		
		int max_st, min_st;
		if (store[0] > store[1]) {
			max_st = store[0];
			min_st = store[1];
		} else {
			max_st = store[1];
			min_st = store[0];
		}
		
		int lim;
		if (N % 2) {
			lim =  N - 1;
			if (store[lim] > max_st)
				max_st = store[lim];
			else if (store[lim] < min_st)
				min_st = store[lim];
		} else
			lim = N;
			
		for (int i = 2; i < lim; i += 2) {
			int max_i, min_i;

			if (store[i] > store[i+1]) {
				max_i = store[i];
				min_i = store[i+1];
			} else {
				max_i = store[i+1];
				min_i = store[i];
			}

			if (max_i > max_st)
				max_st = max_i;

			if (min_i < min_st)
				min_st = min_i;
		}

		printf ("%d\n", 2 * (max_st - min_st));
	}

	return 0;
}
