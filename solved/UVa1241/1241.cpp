#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N, M;
		scanf ("%d%d", &N, &M);

		int n_elem = 1 << N;
		vector<bool> p (n_elem, true);

		for (int i = 0; i < M; i++) {
			int num;
			scanf ("%d", &num);
			p[num - 1] = false;
		}
		
		int n_wo = 0;
		for (int jump = 2; jump <= n_elem; jump <<= 1) 
			for (int i = 0; i < n_elem; i += jump) {
				int c1, c2;
				c1 = i;
				c2 = i + (jump >> 1);

				n_wo += (p[c1] != p[c2]);
				p[c1] = (p[c1] || p[c2]);
			}

		printf ("%d\n", n_wo);
	}

	return 0;
}

		
