#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int
main ()
{
	int N;
	int case_no = 0;

	while (scanf ("%d", &N), N) {
		vector<int> v (MAXN, 0);

		for (int i = 0; i < N; i++) {
			int y, a, b;
			scanf ("%d%d%d", &y, &a, &b);
			
			int j = b - a;
			int mask = (1 << i);
			for (int year = y; year < MAXN; year += j)
				v[year] |= mask;
		}

		int mask = (1 << N) - 1;
		vector<int>::iterator it;
		
		it  = find (v.begin (), v.end (), mask);
		
		printf ("Case #%d:\n", ++case_no);
		if (it == v.end ())
			printf ("Unknown bugs detected.\n\n");
		else
			printf ("The actual year is %d.\n\n", (int) (it - v.begin ()));

	}

	return 0;
}
