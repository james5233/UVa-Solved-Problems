#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int n_beds, budget, n_hotels, n_weeks;
	while (scanf ("%d%d%d%d", &n_beds, &budget, &n_hotels, &n_weeks) == 4) {
		int min_cost = INT_MAX;

		for (int h = 0; h < n_hotels; h++) {
			int price_per_bed;
			scanf ("%d", &price_per_bed);
			
			int max_occupancy = INT_MIN;
			for (int w = 0; w < n_weeks; w++) {
				int beds;
				scanf ("%d", &beds);
				max_occupancy = max (max_occupancy, beds);
			}

			if (max_occupancy >= n_beds) {
				int cost = n_beds * price_per_bed;
				if (cost <= budget)
					min_cost = min (min_cost, cost);
			}
		}

		if (min_cost < INT_MAX)
			printf ("%d\n", min_cost);
		else
			printf ("stay home\n");
	}

	return 0;
}
