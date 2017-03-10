#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int t, T;
	for (scanf ("%d", &T), t = 1; t <= T; t++) {
		int N;
		scanf ("%d", &N);

		int max_speed = INT_MIN;

		for (int i = 0; i < N; i++) {
			int speed;
			scanf ("%d", &speed);

			max_speed = max (max_speed, speed);
		}

		printf ("Case %d: %d\n", t, max_speed);
	}

	return 0;
}
