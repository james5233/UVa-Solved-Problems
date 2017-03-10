#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;

	while (scanf ("%d", &N), N) {
		vector<int> v;
		int n_peaks = 0;

		for (int i = 0; i < N; i++) {
			int h;
			scanf ("%d", &h);
			v.push_back (h);
		}

		for (int i = 1; i < N - 1; i++) {
			if ((v[i-1] < v[i] && v[i+1] < v[i]) || 
				(v[i-1] > v[i] && v[i+1] > v[i]))
				n_peaks++;
		}


		if ((v[N-1] < v[0] && v[1] < v[0]) || 
			(v[N-1] > v[0] && v[1] > v[0]))
			n_peaks++;
		
		if ((v[N-2] < v[N-1] && v[0] < v[N-1]) || 
			(v[N-2] > v[N-1] && v[0] > v[N-1]))
			n_peaks++;

		printf ("%d\n", n_peaks);
	}

	return 0;
}
