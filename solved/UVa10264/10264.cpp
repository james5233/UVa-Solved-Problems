#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;

	while (scanf ("%d", &N) != EOF) {
		int n_vert = 1 << N;

		vector<unsigned char> w (n_vert);
		vector<int> p (n_vert, 0);

		for (int i = 0; i < n_vert; i++) {
			unsigned int num;
			scanf ("%u", &num);
			w[i] = num;
		}

		for (int i = 0; i < n_vert; i++) {
			for (int j = 0; j < N; j++) {
				int pos = i ^ (1 << j);
				p[i] += w[pos];
			}
		}
		
		int max_pot_sum = 0;
		for (int i = 0; i < n_vert; i++) {
			for (int j = 0; j < N; j++) {
				int pos = i ^ (1 << j);
				int s = p[i] + p[pos];
				if (s > max_pot_sum)
					max_pot_sum = s;
			}
		}

		printf ("%d\n", max_pot_sum);
	}

	return 0;
}

