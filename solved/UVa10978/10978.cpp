#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pis;
typedef vector<pis> vpis;
typedef vector<string> vs;
typedef vector<int> vi;

int
main ()
{
	int N;

	while (scanf ("%d", &N), N) {
		vs card;
		vi len;
		
		for (int i = 0; i < N; i++) {
			char c[4];
			int st, end, l;
			scanf (" %[^ ] %n%*[^\n]%n", c, &st, &end);
			l = end - st;

			card.push_back (c);
			len.push_back (l);
		}

		vector<bool> pres (N, true);
		vpis store;
		int cur = 0;
		
		for (int i = 0; i < N; i++) {
			int l = len[i];

			while (l > 1) {
				if (pres[cur])
					l--;

				cur = (cur + 1) % N;
			}
			while (!pres[cur])
				cur = (cur + 1) % N;

			store.push_back (make_pair (cur, card[i]));
			pres[cur] = false;
		}

		sort (store.begin (), store.end ());

		printf ("%s", store[0].second.c_str ());

		for (int i = 1; i < N; i++)
			printf (" %s", store[i].second.c_str ());

		printf ("\n");

	}

	return 0;
}



