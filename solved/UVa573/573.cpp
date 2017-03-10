#include <bits/stdc++.h>

int
main ()
{
	int H, U, D, F;

	while (scanf ("%d%d%d%d", &H, &U, &D, &F), H) {
		int day;
		double h;

		h = 0.0;
		day = 1;

		while (1) {

			double clmb;
			clmb = (1.0 - (F * (day - 1))/100.0) * U;

			if (clmb < 0.0)
				clmb = 0.0;

			h += clmb;

			if (h > H) {
				printf ("success on day %d\n", day);
				break;
			}
			
			h -= D;
			
			if (h < 0.0) {
				printf ("failure on day %d\n", day);
				break;
			}

			day++;
		}
	}

	return 0;
}

