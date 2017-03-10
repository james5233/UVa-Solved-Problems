#include <bits/stdc++.h>

#define CCW (1)
#define  CW (-1)
#define BASE 40

int
main ()
{
	int pos, c[3];
	while (scanf ("%d%d%d%d", &pos, c, c + 1, c + 2), 
	       (pos || c[0] || c[1] || c[2])) {
		int dirn = CW;
		int units = 3 * BASE;

		for (int i = 0; i < 3; i++) {
			while (pos != c[i]) {
				pos = (pos + dirn + BASE) % BASE;
				units++;
			}

			dirn *= -1;
		}

		printf ("%d\n", 9 * units);
	}

	return 0;
}
