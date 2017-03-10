#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N, M;
	while (scanf ("%d%d", &N, &M), N || M) {
		vector<int> jack (N);
		set<int> jill;

		for (int i = 0; i < N; i++) {
			scanf ("%d", &(jack[i]));
		}

		for (int i = 0; i < M; i++) {
			int num;
			scanf ("%d", &num);
			jill.insert (num);
		}

		int ct = 0;
		for (int i = 0; i < N; i++) {
			int num = jack[i];
			set<int>::iterator it = jill.find (num);
			if (it != jill.end ())
				ct++;
		}

		printf ("%d\n", ct);
	}

	return 0;
}
