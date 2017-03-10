#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int H, L;

	while (scanf ("%d%d", &H, &L), H) {
		int h, l;
		int ct;
		
		h = H;
		ct = 0;

		for (l = 1; l <= L; l++) {
			int cur;
			scanf ("%d", &cur);

			if (cur < h)
				ct += (h - cur);

			h = cur;
		}

		printf ("%d\n", ct);
	}

	return 0;
}



