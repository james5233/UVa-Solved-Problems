#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int
main ()
{
	int N;
	while (scanf ("%d", &N), N) {
		vpii v;

		for (int i = 0; i < N; i++) {
			int car, c;
			scanf ("%d%d", &car, &c);

			v.push_back (make_pair (i + c, car));
		}

		sort (v.begin (), v.end ());

		bool valid = true;
		for (int i = 0; i < N; i++)
			if (v[i].first != i) {
				valid = false;
				break;
			}

		if (!valid)
			printf ("-1\n");
		else {
			vpii::iterator it;
			for (it = v.begin (); it != v.end () - 1; it++)
				printf ("%d ", it->second);
			printf ("%d\n", (v.end () - 1)->second);
		}
	}

	return 0;
}
