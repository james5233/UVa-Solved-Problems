#include <bits/stdc++.h>
using namespace std;

#define N_LUMBERJACKS 10

#define CMP(a, b) ((a == b) ? 0 : (((a) < (b)) ? (-1) : 1))
#define NEW_DIRN(p, c) (((p) == (c)) ? (p) : (((p) + (c) - 2*(p)*(c))))
#define VALID(c) (((c) >= -1) && ((c) <= 1))

int
main ()
{
	int T;
	for (scanf ("%d", &T), printf ("Lumberjacks:\n"); T--;) {
		int dirn, prev, cur;
		bool valid;

		valid = true;
		dirn = 0;

		scanf ("%d", &prev);

		for (int i = 1; i < N_LUMBERJACKS; i++) {
			scanf ("%d", &cur);
			int d = CMP (prev, cur);
			dirn = NEW_DIRN (dirn, d);
			if (!VALID (dirn))
				valid = false;

			prev = cur;
		}

		if (valid)
			printf ("Ordered\n");
		else
			printf ("Unordered\n");
	}

	return 0;
}
		
