#include <bits/stdc++.h>
using namespace std;

#define MAXROW 9
#define MAXCOL MAXROW

int
main ()
{
	int T;
	int arr[MAXROW][MAXCOL];

	for (scanf ("%d", &T); T--;) {
		for (int i = 0; i < MAXROW; i += 2) 
			for (int j = 0; j <= i; j += 2)
				scanf ("%d", &(arr[i][j]));

		for (int i = 2; i < MAXROW; i += 2)
			for (int j = 1; j <= i; j += 2) {
				int P, Q, R;
				P = arr[i-2][j-1];
				Q = arr[i][j-1];
				R = arr[i][j+1];

				arr[i][j] = (P - (Q + R)) / 2;
			}

		for (int i = 1; i < MAXROW; i += 2)
			for (int j = 0; j <= i; j++)
				arr[i][j] = arr[i+1][j] + arr[i+1][j+1];

		for (int i = 0; i < MAXROW; i++) {
			for (int j = 0; j < i; j++)
				printf ("%d ", arr[i][j]);
			printf ("%d\n", arr[i][i]);
		}

	}

	return 0;
}
