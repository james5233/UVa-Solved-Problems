#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	while (scanf ("%d", &N), N) {
		int num;
		long cost;
		int steps;
		
		priority_queue< int, vector<int>, greater<int> > pq;

		for (int i = 0; i < N; i++) {
			scanf ("%d", &num);
			pq.push (num);
		}

		steps = N - 1;
		cost = 0L;

		for (int i = 0; i < steps; i++) {
			int n1, n2;
			n1 = pq.top (); pq.pop ();
			n2 = pq.top (); pq.pop ();
			num = n1 + n2;
			pq.push (num);
			cost += num;
		}

		printf ("%ld\n", cost);
	}

	return 0;
}
