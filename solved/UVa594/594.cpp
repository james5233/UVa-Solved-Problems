#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int sav;
	while (scanf ("%d", &sav) != EOF) {
		unsigned int num = (unsigned int)sav;
		unsigned int res = 0;
		unsigned int mask = (1U<<8) - 1U;

		for (int i = 0; i < 4; i++) {
			res = res << 8;
			res |= (num & mask);
			num >>= 8;
		}

		int pr = (int) res;

		printf ("%d converts to %d\n", sav, pr);
	}

	return 0;
}
