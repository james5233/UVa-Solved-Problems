#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		long S, A, F;
		vector<int> v[2];

		scanf ("%ld%ld%ld", &S, &A, &F);

		for (int f = 0; f < F; f++) {
			long s, a;
			scanf ("%ld%ld", &s, &a);
			v[0].push_back (s);
			v[1].push_back (a);
		}
		
		long s, a;

		sort (v[0].begin (), v[0].end ());
		sort (v[1].begin (), v[1].end ());

		s = v[0][(F - 1)/2];
		a = v[1][(F - 1)/2];

		printf ("(Street: %ld, Avenue: %ld)\n", s, a);
	}

	return 0;
}
