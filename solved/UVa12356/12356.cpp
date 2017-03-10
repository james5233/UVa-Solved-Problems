#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int
main ()
{
	int S, B;

	while (scanf ("%d%d", &S, &B), S || B) {
		vpii st (S + 1, make_pair (0, 0));
		for (int i = 0; i < B; i++) {
			int L, R, l, r;
			scanf ("%d%d", &L, &R);

			if (L == 1 || st[L-1].first == 0)
				l = L;
			else
				l = st[L-1].first;

			if (R == S || st[R+1].second == 0)
				r = R;
			else
				r = st[R+1].second;

			st[l].first = l;
			st[l].second = r;

			st[r].first = l;
			st[r].second = r;

			if (l == 1)
				printf ("* ");
			else
				printf ("%d ", l - 1);

			if (r == S)
				printf ("*\n");
			else
				printf ("%d\n", r + 1);
		}
		
		printf ("-\n");
	}

	return 0;
}

