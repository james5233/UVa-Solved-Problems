#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int find_ufds (int i, vi &p, vi &r)
{
	return ((p[i] == i) ? i : (p[i] = find_ufds (p[i], p, r)));
}

int union_ufds (int i, int j, vi &p, vi &r)
{
	int rt_i = find_ufds (i, p, r);
	int rt_j = find_ufds (j, p, r);

	if (rt_i == rt_j)
		return rt_i;
	
	if (r[rt_i] > r[rt_j])
		return (p[rt_j] = rt_i);
	else {
		p[rt_i] = rt_j;
		if (r[rt_i] == r[rt_j])
			r[rt_j]++;
	}

	return rt_j;
}

int
main ()
{
	int N, M;
	while (scanf ("%d %d", &N, &M), N || M) {
		scanf ("%*[^\n]");
		getchar ();
		int a, b;

		unordered_map<string, int> mp;
		vi p (N + 1), r (N + 1);

		for (int i = 0; i < N + 1; i++) {
			p[i] = i;
			r[i] = 0;
		}
		
		#define MAXLLEN 5000
		char s1[MAXLLEN], s2[MAXLLEN];
		for (int i = 1; i <= N; i++) {
			scanf ("%s", s1);
			scanf ("%*[^\n]");
			getchar ();

			mp[s1] = i;
		}
		
		for (int i = 0; i < M; i++) {
			scanf ("%s %s", s1, s2);
			scanf ("%*[^\n]");
			getchar ();

			a = mp[s1];
			b = mp[s2];
			union_ufds (a, b, p, r);
		}
		
		vi grp_sz (N + 1, 0);
		int max_sz = 0;
		for (int i = 1; i <= N; i++) 
				max_sz = max (max_sz, ++grp_sz[find_ufds (i, p, r)]);

		printf ("%d\n", max_sz);
	}

	return 0;
}
