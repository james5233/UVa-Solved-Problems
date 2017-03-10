#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef deque<pii> dqpii;
typedef vector<int> vi;

int
main ()
{
	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N;
		scanf ("%d", &N);

		vi p, q;

		for (int n = 0; n < N; n++) {
			int petrol;
			scanf ("%d", &petrol);
			p.push_back (petrol);
		}
		
		for (int n = 0; n < N; n++) {
			int cons;
			scanf ("%d", &cons);
			q.push_back (cons);
		}

		dqpii m;
		int sum = 0;

		for (int n = 0; n < N; n++) {
			sum += p[n] - q[n];

			while (m.size () && m.back ().second >= sum)
				m.pop_back ();

			m.push_back (make_pair(n, sum));
		}
		
		int s = 0;
		int n;

		for (n = 0; n < N; n++) {
			int l = m.front ().second;

			if (l - s >= 0) {
				printf ("Case %d: Possible from station %d\n", t, n + 1);
				break;
			}

			sum += p[n] - q[n];
			while (m.size () && m.front ().first <= n)
				m.pop_front ();

			while (m.size () && m.back ().second >= sum)
				m.pop_back ();

			m.push_back (make_pair (n + N, sum));
			s += p[n] - q[n];
		}

		if (n == N)
			printf ("Case %d: Not possible\n", t);
	}

	return 0;
}

