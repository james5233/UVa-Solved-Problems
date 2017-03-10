#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define PRN_ARR(h) do {\
			for (int i = 1; i <= 3; i++) {\
				for (int j = 1; j <= 3; j++)\
					printf ("%d", h[i][j]);\
				printf ("\n");\
			}\
		} while (0)

int
main ()
{
	int T;
	char str[3][4];
	int arr[2][5][5], sav[5][5];

	int (*g)[5], (*h)[5], (*temp)[5];

	for (scanf ("%d", &T); T--;) {
		scanf (" %s %s %s", str[0], str[1], str[2]);
		
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				arr[0][i][j] = arr[1][i][j] = sav[i][j] = 0;


		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				arr[0][i][j] = sav[i][j] = str[i-1][j-1] - '0';
		
		g = arr[0];
		h = arr[1];
		
		int ct;
		bool eq;
		
		D( printf ("DEBUG: Initial\n");
		PRN_ARR (g); )

		for (ct = -1; ct < 512; ct++) {

			eq = true;
			for (int i = 1; i <= 3 && eq; i++)
				for (int j = 1; j <= 3; j++)
					if (g[i][j] != 0) {
						eq = false;
						break;
					}

			if (eq)
				break;
			
			for (int i = 1; i <= 3; i++)
				for (int j = 1; j <= 3; j++)
					h[i][j] = (g[i-1][j] + g[i][j-1] + g[i+1][j] + g[i][j+1]) & 1;
			
			D( printf ("DEBUG: ct = %d\n", ct);
			PRN_ARR (h); )

			temp = g;
			g = h;
			h = temp;
		}

		if (ct >= 0 && ct < 512 && eq)
			printf ("%d\n", ct);
		else
			printf ("-1\n");

	}

	return 0;
}
