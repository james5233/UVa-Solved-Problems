#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	int set_num = 0;

	while (scanf ("%d", &N), N) {
		vector<int> v;
		int sum  = 0;

		for (int i = 0; i < N; i++) {
			int h;
			scanf ("%d", &h);

			sum += h;
			v.push_back (h);
		}

		int avg, moves;

		avg = sum / N;
		moves  = 0;

		for (int i = 0; i < N; i++) 
			if (v[i] > avg)
				moves += v[i] - avg;
		
		set_num++;
		printf ("Set #%d\n", set_num);
		printf ("The minimum number of moves is %d.\n\n", moves);

	}

	return 0;
}
