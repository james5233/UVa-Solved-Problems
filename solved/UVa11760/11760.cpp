#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int R, C, N;
	int case_no = 0;

	while (scanf ("%d %d %d", &R, &C, &N), R || C || N) {
		vector<int> coord[2];

		for (int i = 0; i < N; i++) {
			int r, c;
			scanf ("%d %d", &r, &c);
			coord[0].push_back (r);
			coord[1].push_back (c);
		}

		int arif_r, arif_c;
		scanf ("%d %d", &arif_r, &arif_c);

		int safe_r, safe_c;
		
		safe_r = (1 << 3) - 1;
		safe_c = (1 << 3) - 1;

		if (arif_r - 1 < 0)
			safe_r &= ~1;

		if (arif_r + 1 >= R)
			safe_r &= ~4;

		if (arif_c - 1 < 0)
			safe_c &= ~1;

		if (arif_c + 1 >= C)
			safe_c &= ~4;

		for (int i = 0; i < N && safe_r && safe_c; i++) {
			int r_d, c_d;

			r_d = coord[0][i] - arif_r;
			c_d = coord[1][i] - arif_c;

			if (r_d >= -1 && r_d <= 1)
				safe_r &= ~(1 << (1 + r_d));
				
			if (c_d >= -1 && c_d <= 1)
				safe_c &= ~(1 << (1 + c_d));
		}
		
		printf ("Case %d: ", ++case_no);
		if (safe_r && safe_c && ((safe_r & 2) | (safe_c & 2))) {
			printf ("Escaped again! More 2D grid problems!\n");
		}
		else
			printf ("Party time! Let\'s find a restaurant!\n");
	}

	return 0;
}
