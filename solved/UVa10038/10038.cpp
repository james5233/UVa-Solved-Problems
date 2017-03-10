#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	while (scanf ("%d", &N) != EOF) {
		vector<bool> v (N, false);
		
		int prev, cur;
		scanf ("%d ", &prev);

		for (int i = 1; i < N; i++) {
			scanf ("%d ", &cur);
			int l = abs (prev - cur);

			if (l >= 1 && l < N)
				v[l] = true;

			prev = cur;
		}
		
		int i;
		for (i = 1; i < N && v[i] == true; i++);

		if (i == N)
			printf ("Jolly\n");
		else
			printf ("Not jolly\n");
	}

	return 0;
}
