#include <bits/stdc++.h>
using namespace std;

#define SET_BIT_64(x, n) ((x) |= (((uint64_t)1) << (n)))
#define SET_BIT_128(x, n) do {\
	if (n < 64) \
		SET_BIT_64 (x.first, n); \
	else \
		SET_BIT_64 (x.second, n - 64); \
} while (0)

typedef pair<uint64_t, uint64_t> pii;
typedef vector<pii> vpii;

#define MAXLLEN 100

int
main ()
{
	int N;

	for (scanf ("%d ", &N); N--;) {
		int P, T;
		scanf ("%d %d", &P, &T);
		scanf ("%*[^\n]");
		getchar ();

		vpii v (P, make_pair ((uint64_t)0, (uint64_t)0));

		char line[MAXLLEN];
		while (fgets (line, MAXLLEN, stdin) && *line != '\n') {
			int pr, tr;
			sscanf (line, "%d %d", &pr, &tr);
			pr--; tr--;
			SET_BIT_128 (v[pr], tr);
		}

		sort (v.begin (), v.end ());
		pii prev = v[0];
		int ct = 1;
			
		//for (int i = 0; i < P; i++)
		//	printf ("(%" PRIu64 ", %" PRIu64 ")\n", v[i].first, v[i].second);

		for (int i = 1; i < P; i++) {
			pii cur = v[i];
			if (cur != prev)
				ct++;
			prev = cur;
		}

		printf ("%d\n", ct);

		if (N)
			printf ("\n");
	}

	return 0;
}
