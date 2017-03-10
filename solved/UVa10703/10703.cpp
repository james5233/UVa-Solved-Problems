#include <bits/stdc++.h>
using namespace std;

#define XOR_SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)

int
main ()
{
	int W, H, N;

	while (scanf (" %d %d %d", &W, &H, &N), W || H || N) {
		int s[W + 1][H + 1];

		for (int x = 1; x <= W; x++)
			for (int y = 1; y <= H; y++)
				s[x][y] = 1;

		while (N--) {
			int x1, y1, x2, y2;
			scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
			
			if (x2 < x1)
				XOR_SWAP (x1, x2);

			if (y2 < y1)
				XOR_SWAP (y1, y2);

			for (int x = x1; x <= x2; x++)
				for (int y = y1; y <= y2; y++)
					s[x][y] = 0;
		}

		int rem = 0;
		for (int x = 1; x <= W; x++)
			for (int y = 1; y <= H; y++)
				rem += s[x][y];

		if (!rem)
			printf ("There is no empty spots.\n");
		else if (rem == 1)
			printf ("There is one empty spot.\n");
		else
			printf ("There are %d empty spots.\n", rem);
	}

	return 0;
}
