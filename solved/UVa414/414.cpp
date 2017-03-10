#include <bits/stdc++.h>
using namespace std;

#define LEN 25

int
main ()
{
	int N;

	while (scanf ("%d", &N), N) {
		int min_ct = LEN + 2;
		int tot_ct = 0;

		for (int n = 0; n < N; n++) {
			char arr[LEN];
			scanf (" %25c", arr);
			
			int ct = 0;
			for (int i = 0; i < LEN; i++)
				if (arr[i] == ' ')
					ct++;

			min_ct = min (min_ct, ct);
			tot_ct += ct;
		}

		tot_ct -= (N * min_ct);
		printf ("%d\n", tot_ct);
	}

	return 0;
}

