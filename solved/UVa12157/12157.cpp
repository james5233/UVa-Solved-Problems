#include <bits/stdc++.h>
using namespace std;

#define MILE_BASE 30
#define JUICE_BASE 60

#define MILE_RATE 10
#define JUICE_RATE 15

int
main ()
{
	int T;
	scanf ("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf ("%d", &N);

		int mile, juice;

		mile = juice = 0;
		for (int n = 0; n < N; n++) {
			int tm;
			scanf ("%d", &tm);

			mile += ((tm + MILE_BASE ) / MILE_BASE) * MILE_RATE;
			juice += ((tm + JUICE_BASE ) / JUICE_BASE) * JUICE_RATE;
		}

		int min_cost = min (mile, juice);
		printf ("Case %d:", t);
		if (mile == min_cost)
			printf (" Mile");
		if (juice == min_cost)
			printf (" Juice");

		printf (" %d\n", min_cost);
	}

	return 0;
}
