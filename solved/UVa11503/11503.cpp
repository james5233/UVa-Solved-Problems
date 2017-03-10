#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unordered_map<string, int> umapsi;

int find_ufds (int a, vi &p, vi&r)
{
	return  ((p[a] == a) ? a : (p[a] = find_ufds (p[a], p, r)));
}

int ct_union_ufds (int a, int b, vi &p, vi &r, vi &ct)
{
	int p_a = find_ufds (a, p, r);
	int p_b = find_ufds (b, p, r);

	if (p_a == p_b)
		return ct[p_a];

	if (r[p_a] > r[p_b]) {
		p[p_b] = p_a;
		ct[p_a] += ct[p_b];
		return ct[p_a];
	} else {
		p[p_a] = p_b;
		ct[p_b] += ct[p_a];
		if (r[p_a] == r[p_b])
			r[p_b]++;

		return ct[p_b];
	}
}

#define MAXLLEN 1000

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int M;
		int N = 0;

		scanf ("%d", &M);
		scanf ("%*[^\n]");
		getchar ();

		umapsi mp;
		umapsi::iterator it;

		vii lst;
		
		char s1[MAXLLEN], s2[MAXLLEN];
		for (int i = 0; i < M; i++) {
			scanf ("%s %s", s1, s2);
			scanf ("%*[^\n]");
			getchar ();

			int a, b;

			if ((it = mp.find (s1)) == mp.end ()) {
				mp[s1] = N;
				a = N++;
			} else
				a = mp[s1];
			
			if ((it = mp.find (s2)) == mp.end ()) {
				mp[s2] = N;
				b = N++;
			} else
				b = mp[s2];

			lst.push_back (make_pair (a, b));
		}
		
		vi p (N), r (N), ct (N);

		for (int i = 0; i < N; i++) {
			p[i] = i;
			r[i] = 0;
			ct[i] = 1;
		}

		for (int i = 0; i < M; i++) {
			ii temp = lst[i];
			printf ("%d\n", ct_union_ufds (temp.first, temp.second, p, r, ct));
		}
	}

	return 0;
}
