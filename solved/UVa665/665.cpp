#include <bits/stdc++.h>
using namespace std;

#define UNKNOWN 0
#define POSSIBLY_LIGHT 1
#define POSSIBLY_HEAVY 2
#define CORRECT_WEIGHT 3

int
main ()
{
	int T;
	bool first = true;
	
	for (scanf ("%d ", &T); T--;) {
		int N, W;
		scanf ("%d %d ", &N, &W);

		vector<int> status (N + 1, UNKNOWN);
		for (int w = 0; w < W; w++) {
			int P;
			scanf ("%d", &P);

			vector<int> left, right;

			for (int p = 0; p < P; p++) {
				int i;
				scanf ("%d ", &i);
				left.push_back (i);
			}

			for (int p = 0; p < P; p++) {
				int i;
				scanf ("%d ", &i);
				right.push_back (i);
			}
			
			char dirn[20];
			scanf ("%s ", dirn);

			if (*dirn == '<') {
				for (int p = 0; p < P; p++) {
					if (status[left[p]] == UNKNOWN)
						status[left[p]] = POSSIBLY_LIGHT;
					else if (status[left[p]] == POSSIBLY_HEAVY)
						status[left[p]] = CORRECT_WEIGHT;
				}
				
				for (int p = 0; p < P; p++) {
					if (status[right[p]] == UNKNOWN)
						status[right[p]] = POSSIBLY_HEAVY;
					else if (status[right[p]] == POSSIBLY_LIGHT)
						status[right[p]] = CORRECT_WEIGHT;
				}
			} else if (*dirn == '>') {
				for (int p = 0; p < P; p++) {
					if (status[left[p]] == UNKNOWN)
						status[left[p]] = POSSIBLY_HEAVY;
					else if (status[left[p]] == POSSIBLY_LIGHT)
						status[left[p]] = CORRECT_WEIGHT;
				}
				
				for (int p = 0; p < P; p++) {
					if (status[right[p]] == UNKNOWN)
						status[right[p]] = POSSIBLY_LIGHT;
					else if (status[right[p]] == POSSIBLY_HEAVY)
						status[right[p]] = CORRECT_WEIGHT;
				}
			} else {
				for (int p = 0; p < P; p++)
					status[left[p]] = status[right[p]] = CORRECT_WEIGHT;
			}
		}

		int ct = 0;
		int coin = 0;
		for (int i = 1; i <= N; i++)
			if (status[i] != CORRECT_WEIGHT) {
				coin = i;
				ct++;
			}

		if (first)
			first = false;
		else
			printf ("\n");

		if (ct == 1)
			printf ("%d\n", coin);
		else
			printf ("0\n");
	}

	return 0;
}





	
