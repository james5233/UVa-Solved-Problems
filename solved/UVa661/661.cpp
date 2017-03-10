#include <bits/stdc++.h>
using namespace std;

#define off false
#define on true

int
main ()
{
	int N, M, C, seq_num;

	seq_num = 0;
	while (scanf ("%d%d%d", &N, &M, &C), (N || M || C)) {
		vector<int> cons (N + 1);
		vector<bool> state (N + 1, off);
		int cur, max_cur;

		for (int n = 1; n <= N; n++)
			scanf ("%d", &cons[n]);
		
		max_cur = cur = 0;
		for (int m = 1; m <= M; m++) {
			int n;
			scanf ("%d", &n);

			if (state[n] == on) {
				state[n] = off;
				cur -= cons[n];
			} else {
				state[n] = on;
				cur += cons[n];

				if (cur > max_cur)
					max_cur = cur;
			}
		}
		
		seq_num++;
		printf ("Sequence %d\n", seq_num);
		if (max_cur > C)
			printf ("Fuse was blown.\n\n");
		else {
			printf ("Fuse was not blown.\n");
			printf ("Maximal power consumption was %d amperes.\n\n", max_cur);
		}
	}

	return 0;
}
