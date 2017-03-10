#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int D, P;
		scanf ("%d%d", &D, &P);

		vector<bool> day (D + 1, false);
		for (int p = 0; p < P; p++) {
			int h;
			scanf ("%d", &h);

			int d = h;
			while (d <= D) {
				day[d] = true;
				d += h;
			}
		}
		
		int ct = 0;
		for (int d = 1; d <= D; d++)
			if (day[d] && d%7 != 6 && d%7 != 0)
				ct++;

		printf ("%d\n", ct);
	}

	return 0;
}
