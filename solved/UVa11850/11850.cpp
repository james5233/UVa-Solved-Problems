#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;

	while (scanf ("%d", &N), N) {
		vector<int> pos;

		for (int i = 0; i < N; i++) {
			int p;
			scanf ("%d", &p);
			pos.push_back (p);
		}

		sort (pos.begin (), pos.end ());

		int s = 0;
		int fuel  = 200;
		bool possible = true;

		for (int i = 0; i < N && possible; i++) {
			fuel = 200 - (pos[i] - s);
			if (fuel >= 0) {
				s = pos[i];
				fuel = 200;
			}
			else 
				possible = false;
		}

		fuel -= 2*(1422 - s);
		if (fuel < 0)
			possible = false;

		if (possible)
			printf ("POSSIBLE\n");
		else
			printf ("IMPOSSIBLE\n");
	}

	return 0;
}
