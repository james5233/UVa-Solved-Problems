#include <bits/stdc++.h>
using namespace std;

#define MAX_STR 50

int
main ()
{
	char name[2][MAX_STR];

	while (gets (name[0]) && gets (name[1])) { 
		long sum[2];
		
		/*printf ("[%s] [%s]\n", name[0], name[1]);*/
		for (int i = 0; i < 2; i++) {
			sum [i] = 0;
			char *p = name[i];
			
			while (*p) {
				if (*p >= 'a' && *p <= 'z')
					sum[i] += (*p - 'a') + 1;
				else if (*p >= 'A' && *p <= 'Z')
					sum[i] += (*p - 'A') + 1;

				while (sum[i] >= 10)
					sum[i] = sum[i]/10 + sum[i]%10;

				p++;
			}
		}

		int lo, hi;
		lo = min (sum[0], sum[1]);
		hi = max (sum[0], sum[1]);
		
		if (hi != 0)
			printf ("%.2f %%\n", (100.0 * lo)/hi);
		else
			printf ("\n");
	}
	return 0;
}


