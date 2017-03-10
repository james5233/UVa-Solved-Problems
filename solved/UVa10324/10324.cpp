#include <bits/stdc++.h>
using namespace std;

#define MAX_STR 1000005
char str[MAX_STR];

int main ()
{
	long st, end;
	int status;
	int case_num = 0;

	while (status = scanf (" %ln%s%ln", &st, str, &end), 
  (status == 1 && end > st)) {
		vector<long> ind;
		vector<bool> tp;
		
		long l = end - st;

		int cur = (str[0] - '0');
		ind.push_back (0);
		tp.push_back (cur == 1);

		for (long i = 1; i < l; i++) {
			int v = (str[i] - '0');

			if (v != cur) {
				ind.push_back (i);
				tp.push_back (!cur);
				cur = !cur;
			}
		}
		
		long C;
		scanf ("%ld", &C);
		
		printf ("Case %d:\n", ++case_num);

		for (long c = 0; c < C; c++) {
			long b[2];
			scanf ("%ld%ld", b, b + 1);

			long lo, hi;
			lo = min (b[0], b[1]);
			hi = max (b[0], b[1]);

			vector<long>::iterator it;
			it = lower_bound (ind.begin (), ind.end (), lo);
			if (it == ind.end ())
				printf ("Yes\n");
			else {
				if (*it != lo)
					it--;
				if ((it + 1 == ind.end ()) || *(it + 1) > hi)
					printf ("Yes\n");
				else
					printf ("No\n");
			}
		}
	}

	return 0;
}
