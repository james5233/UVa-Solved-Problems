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
	int case_num = 0;

	while (scanf ("%d %d", &N, &M), N || M) {
		int a, b;

		vi p (N + 1), r (N + 1);

		for (int i = 0; i < N + 1; i++) {
			p[i] = i;
			r[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			scanf ("%d %d", &a, &b);
			union_ufds (a, b, p, r);
		}
		
		int n_roots = 0;
		for (int i = 1; i <= N; i++)
			if (p[i] == i)
				n_roots++;

		printf ("Case %d: %d\n", ++case_num, n_roots);
	}

	return 0;
}
