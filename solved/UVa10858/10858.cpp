#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi res;
vi lag;

void
bk_trace (int N, vector<int> &v) {
	if (N > 1) {
		int lim = (int)(sqrt (N));
		int l = v.size ();
		int st;
		if (l > 0)
			st = v[l - 1];
		else
			st = 2;

		for (int i = st; i <= lim; i++) {
			if (N % i == 0) {
				v.push_back (i);
				bk_trace (N/i, v);
				v.pop_back ();
			}
		}
		
		if (l) {
			/*
			vector<int>::iterator it;
			for (it = v.begin (); it != v.end (); it ++)
				printf ("%d ", *it);
			printf ("%d\n", N);
			*/
			res.push_back (v);
			lag.push_back (N);
	  }
	}
}


int
main ()
{
	int N;

	while (scanf ("%d", &N), N) {
		if (N == 1) {
			printf ("0\n");
			continue;
		}

		vector<int> v;
		res.clear ();
		lag.clear ();
		bk_trace(N, v);
		
		int len = res.size ();
		printf ("%d\n", len);
		for (int i = 0; i < len; i++) {
			vector<int>::iterator it;
			for (it = res[i].begin (); it != res[i].end (); it ++)
				printf ("%d ", *it);
			printf ("%d\n", lag[i]);
		}
	}

	return 0;
}
