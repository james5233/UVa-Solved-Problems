#include <bits/stdc++.h>

#define MAX_STR 120
#define NUM_SITES 10

int
main ()
{
	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		char sites[NUM_SITES][MAX_STR];
		int rank[NUM_SITES];
		int max_rank;

		max_rank = INT_MIN;
		for (int i = 0; i < NUM_SITES; i++) {
			scanf (" %s %d", sites[i], rank + i);
			if (rank[i] > max_rank)
				max_rank = rank[i];
		}

		printf ("Case #%d:\n", t);
		for (int i = 0; i < NUM_SITES; i++)
			if (rank[i] == max_rank)
				printf ("%s\n", sites[i]);

	}

	return 0;
}
