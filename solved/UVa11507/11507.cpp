#include <bits/stdc++.h>
using namespace std;

int 
main ()
{
	int L;
	int bend[6][5] = { 0, 2, 3, 4, 5,
									  1, 3, 2, 5, 4,
										2, 1, 0, 2, 2,
										3, 0, 1, 3, 3,
										4, 4, 4, 1, 0,
										5, 5, 5, 0, 1 };

	while (scanf ("%d", &L), L) {
		int cur = 0;
		for (int l = 1; l < L; l++) {
			char s[5];
			int dirn;
			scanf ("%s", s);

			if (!strcmp (s, "No"))
				dirn = 0;
			else if (!strcmp (s, "+y"))
				dirn = 1;
			else if (!strcmp (s, "-y"))
				dirn = 2;
			else if (!strcmp (s, "+z"))
				dirn = 3;
			else 
				dirn = 4;

			cur = bend[cur][dirn];
		}

		const char str[6][3] = {"+x", "-x", "+y", "-y", "+z", "-z"};
		
		printf ("%s\n", str[cur]);
	}
	return 0;
}


