#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	scanf ("%d", &T);

	for (int t = 1; t <= T; t++) {
		int R, C, M, N;
		scanf ("%d %d %d %d", &R, &C, &M, &N);

		int tot = R * C;
		vector<int> freq (26, 0);

		for (int r = 0; r < R; r++) {
			char str[50];
			scanf (" %s", str);

			for (int c = 0; c < C; c++)
				freq[str[c] - 'A']++;
		}

		int mx = *(max_element (freq.begin (), freq.end ()));
		int ct_mx = count (freq.begin (), freq.end (), mx);

		int tot_mx = ct_mx * mx;
		int rem = tot - tot_mx;

		printf ("Case %d: %d\n", t, tot_mx * M + rem * N);
	}

	return 0;
}
