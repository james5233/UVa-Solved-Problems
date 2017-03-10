#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	for (scanf ("%d", &N); N--;) {
		int n, k;
		scanf ("%d%d", &n, &k);
		
		int res = 0;
		for (int i = 0; i < n; i++) {
			int n_0 = k >> i;
			res |= (((n_0 + 1) >> 1) & 1) << i;
		}

		printf ("%d\n", res);
	}

	return 0;
}

