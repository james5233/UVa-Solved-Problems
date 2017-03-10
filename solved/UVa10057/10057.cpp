#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	long N;
	while (scanf ("%ld", &N) != EOF) {
		vector<unsigned int> v;
		for (long i = 0; i < N; i++) {
			unsigned int u;
			scanf ("%u", &u);
			v.push_back (u);
		}

		sort (v.begin (), v.end ());

		unsigned int lo = v[(N - 1L) / 2L];
		unsigned int hi = v[N / 2L];
		
		long ct = 0;
		for (long i = (N - 1L) / 2L; i >= 0; i--)
			if (v[i] >= lo && v[i] <= hi)
				ct++;

		for (long i = (N - 1L)/2L + 1; i < N; i++)
			if (v[i] >= lo && v[i] <= hi)
				ct++;

		printf ("%u %ld %u\n", lo, ct, hi - lo + 1);
	}

	return 0;
}

