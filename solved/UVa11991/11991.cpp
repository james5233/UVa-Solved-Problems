#include <bits/stdc++.h>
using namespace std;

int 
main ()
{
	int N, M;
	while (scanf ("%d %d", &N, &M) == 2) {
		unordered_map<int, vector<int> > mp;
		unordered_map<int, vector<int> >::iterator it;
		int k, v;

		for (int i = 1; i <= N; i++) {
			scanf ("%d", &v);
			mp[v].push_back (i);
		}

		for (int i = 1; i <= M; i++) {
			scanf ("%d %d", &k, &v);

			it = mp.find (v);
			if (it == mp.end ())
				printf ("0\n");
			else {
				int sz = it->second.size ();
				if (k > sz)
					printf ("0\n");
				else
					printf ("%d\n", it->second[k - 1]);
			}
		}
	}

	return 0;
}

