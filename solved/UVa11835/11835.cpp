#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int
main ()
{
	int G, P;
	while (scanf ("%d%d", &G, &P), G || P) {
		vvpii race (G);
		vi points (P + 1);
		
		for (int g = 0; g < G; g++) {
			for (int j = 1; j <= P; j++) {
				int n;
				scanf ("%d", &n);
				race[g].push_back (make_pair (n, j));
			}

			sort (race[g].begin (), race[g].end ());
		}

		int S;
		scanf ("%d", &S);

		for (int i = 0; i < S; i++) {
			int n;
			scanf ("%d", &n);

			vi score;
			
			for (int j = 0; j < n; j++) {
				int pt;
				scanf ("%d", &pt);
				score.push_back (pt);
			}
			
			fill (points.begin () + 1, points.end (), 0);
			for (int g = 0; g < G; g++) {
				for (int r = 0; r < n; r++)
					points[race[g][r].second] += score[r];
			}

			int mx = *(max_element (points.begin () + 1, points.end ()));
			bool first = true;
			for (int j = 1; j <= P; j++) {
				if (points[j] == mx) {
					if (first) {
						printf ("%d", j);
						first = false;
					} else
						printf (" %d", j);
				}
			}
			printf ("\n");
		}
	}

	return 0;
}
