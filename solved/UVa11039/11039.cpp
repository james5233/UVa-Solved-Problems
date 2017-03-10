#include <bits/stdc++.h>
using namespace std;

#define RED (-1)
#define BLUE 1

int
main ()
{
	long T;
	for (scanf ("%ld", &T); T--;) {
		long N;
		scanf ("%ld", &N);

		vector<long> pos, neg;

		for (long n = 0; n < N; n++) {
			long num;
			scanf ("%ld", &num);

			if (num < 0)
				neg.push_back (-num);
			else
				pos.push_back (num);
		}

		sort (neg.begin (), neg.end (), greater<long>() );
		sort (pos.begin (), pos.end (), greater<long>() );

		long p_sz, n_sz;
		p_sz = pos.size ();
		n_sz = neg.size ();

		if (p_sz == 0 && n_sz == 0)
			printf ("0\n");
		else if (min (p_sz, n_sz) == 0)
			printf ("1\n");
		else {
			long M = max (pos[0], neg[0]);
			int color;

			if (M == pos[0])
				color = BLUE;
			else
				color = RED;

			long n_floors  = 0;
			long p_i, n_i;

			p_i = n_i = 0;
			while (true) {
				if (color == BLUE) {
					while (p_i < p_sz && pos[p_i] > M)
						p_i++;

					if (p_i < p_sz) {
						n_floors++;
						M = pos[p_i++];
						color = RED;
					} else
						break;
				} else {
					while (n_i < n_sz && neg[n_i] > M)
						n_i++;

					if (n_i < n_sz) {
						n_floors++;
						M = neg[n_i++];
						color = BLUE;
					} else
						break;
				}
			}

			printf ("%ld\n", n_floors);
		}
	}

	return 0;
}
	

					

