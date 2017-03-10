#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N, R, C, K;

	while (scanf ("%d%d%d%d", &N, &R, &C, &K), N || R || C || K) {
		int arr[2][R + 2][C + 2];
		int (*g)[C + 2], (*h)[C + 2], (*temp)[C + 2];

		for (int i = 0; i < R + 2; i++)
			arr[0][i][0] = arr[0][i][C + 1] = arr[1][i][0] = arr[1][i][C + 1]= -1;

		for (int j = 0; j < C + 2; j++)
			arr[0][0][j] = arr[0][R + 1][j] = arr[1][0][j] = arr[1][R + 1][j]= -1;
		
		g = arr[0]; h = arr[1];

		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				scanf ("%d", &(g[i][j]));

		for (int k = 0; k < K; k++) {
			for (int i = 1; i <= R; i++)
				for (int j = 1; j <= C; j++) {
					h[i][j] = g[i][j];
					for (int p = i - 1; p <= i + 1; p += 2)
						if (g[p][j] >= 0 && (g[p][j] + 1) % N == g[i][j])
							h[i][j] = g[p][j];
					for (int q = j - 1; q <= j + 1; q += 2)
						if (g[i][q] >= 0 && (g[i][q] + 1) % N == g[i][j])
							h[i][j] = g[i][q];
				}

			temp = g;
			g = h;
			h = temp;
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j < C; j++)
				printf ("%d ", g[i][j]);
			printf ("%d\n", g[i][C]);
		}
	}

	return 0;
}

