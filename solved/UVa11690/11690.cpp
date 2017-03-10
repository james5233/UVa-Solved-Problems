#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int find_ufds (int a, vi &p, vi &r)
{
	return ((p[a] == a) ? a : (p[a] = find_ufds (p[a], p, r)));
}

int union_ufds (int a, int b, vi &p, vi &r)
{
	int p_a = find_ufds (a, p, r);
	int p_b = find_ufds (b, p, r);

	if (p_a == p_b)
		return p_a;

	if (r[p_a] > r[p_b])
		return (p[p_b] = p_a);
	else {
		p[p_a] = p_b;
		if (r[p_a] == r[p_b])
			r[p_b]++;
	}

	return p_b;
}

int 
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N, M;
		scanf ("%d %d", &N, &M);

		vi p (N), r (N);
		vector<long> owes (N);

		for (int i = 0; i < N; i++) {
			scanf ("%ld", &(owes[i]));
			p[i] = i;
			r[i] = 0;
		}

		int a, b;
		for (int i = 0; i < M; i++) {
			scanf ("%d %d", &a, &b);
			union_ufds (a, b, p, r);
		}

		for (int i = 0; i < N; i++) {
			int p_i = find_ufds (i, p, r);
			if (p_i != i)
				owes[p_i] += owes[i];
		}

		bool possible = true;

		for (int i = 0; i < N && possible; i++)
			if (p[i] == i && owes[i] != 0)
				possible = false;

		if (possible)
			printf ("POSSIBLE\n");
		else
			printf ("IMPOSSIBLE\n");
	}

	return 0;
}
