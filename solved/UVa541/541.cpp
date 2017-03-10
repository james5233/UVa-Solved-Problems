#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	while (scanf ("%d", &N), N) {
		int arr[N][N], i, j;

		for (i = 0; i < N; i++)
			for ( j  = 0; j < N; j++)
				scanf ("%d", &(arr[i][j]));
		
		int n_rdv, i_rdv;
		n_rdv = 0;
		for (i = 0; i < N; i++) {
			int r = 0;
			for (j = 0; j < N; j++)
				r ^= arr[i][j];

			if (r == 1) {
				n_rdv++;
				i_rdv = i;
			}
		}
		
		int n_cdv, i_cdv;
		n_cdv = 0;
		for (j = 0; j < N; j++) {
			int c = 0;
			for (i = 0; i < N; i++)
				c ^= arr[i][j];

			if (c == 1) {
				n_cdv++;
				i_cdv = j;
			}
		}

		if (n_rdv == 0 && n_cdv == 0)
			printf ("OK\n");
		else if (n_rdv == 1 && n_cdv == 1)
			printf ("Change bit (%d,%d)\n", i_rdv + 1, i_cdv + 1);
		else
			printf ("Corrupt\n");
	}

	return 0;
}

