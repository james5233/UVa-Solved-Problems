#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N;
		scanf ("%d", &N);

		unordered_map<int, int> owns;
		vector<int> uniq_ct (N, 0);
		int n_uniq = 0;

		for (int i = 0; i < N; i++) {
			int M;
			scanf ("%d", &M);

			for (int j = 0; j < M; j++) {
				int num;
				scanf ("%d", &num);

				unordered_map<int, int>::iterator it = owns.find (num);
				if (it == owns.end ()) {
					owns[num] = i;
					uniq_ct[i]++;
					n_uniq++;
				} else {
					if (it->second >= 0 && i != it->second) {
						uniq_ct[it->second]--;
						n_uniq--;
						owns[num] = -1;
					}
				}
			}
		}
		
		if (!n_uniq)
			n_uniq = 1;
		
		printf ("Case %d:", t);
		for (int i = 0; i < N; i++) {
			printf (" %.6f%%", (uniq_ct[i] * 100.0)/n_uniq);
		}
		printf ("\n");
	}

	return 0;
}


						

