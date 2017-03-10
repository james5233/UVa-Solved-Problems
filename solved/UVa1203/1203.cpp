#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef priority_queue<piii> pqpiii;

#define MAKE_TRI(x, y, z) (make_pair (make_pair (-(x), -(y)), (z)))
#define TIME(x) (-((x).first.first))
#define ID(x) (-((x).first.second))
#define PERIOD(x) ((x).second)

#define MAXLLEN 200

int
main ()
{
	pqpiii pq;
	char line[MAXLLEN];
	int tm, id, period;
	int K;

	while (fgets (line, MAXLLEN, stdin), *line != '#') {
		sscanf (line, "%*s %d %d", &id, &period);
		pq.push (MAKE_TRI (period, id, period));
	}

	scanf ("%d", &K);

	for (int i = 0; i < K; i++) {
		piii p = pq.top ();
		tm = TIME (p);
		id = ID (p);
		period = PERIOD (p);
		pq.pop ();

		printf ("%d\n", id);
		pq.push (MAKE_TRI (tm + period, id, period));
	}

	return 0;
}
