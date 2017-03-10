#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int
main ()
{	
	long arr[MAXN][MAXN];

	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N;
		scanf (" N = %d", &N);
		
		bool symmetric = true;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				scanf ("%ld", &(arr[i][j]));
				if (arr[i][j] < 0L)
					symmetric = false;
			}

		int rs, re;

		for (rs = 0, re = N - 1; rs < re; rs++, re--) {
			int D, cs, ce;
			D = re - rs;
			cs = rs;
			ce = re;

			for (int d = 0; d < D; d++) {
				if (arr[rs + d][cs] != arr[re - d][ce]) {
					symmetric = false;
					break;
				}

				if (arr[re][cs + d] != arr[rs][ce - d]) {
					symmetric = false;
					break;
				}
			}
		}

		if (symmetric)
			printf ("Test #%d: Symmetric.\n", t);
		else
			printf ("Test #%d: Non-symmetric.\n", t);

	}

	return 0;
}
				


