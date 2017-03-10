#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void init_ufds (vi &p, vi &r)
{
	int len = p.size ();
	for (int i = 0; i < len; i++) {
		p[i] = i;
		r[i] = 0;
	}
}

int find_set_ufds (int a, vi &p, vi &r)
{
	return ((p[a] == a) ? a : (p[a] = find_set_ufds (p[a], p, r)));
}

void union_ufds (int a, int b, vi &p, vi &r)
{
	int rt_a, rt_b;
	rt_a = find_set_ufds (a, p, r);
	rt_b = find_set_ufds (b, p, r);

	if (rt_a != rt_b) {
		if (r[rt_a] > r[rt_b])
			p[rt_b] = rt_a;
		else {
			p[rt_a] = rt_b;
			if (r[rt_a] == r[rt_b])
				r[rt_b]++;
		}
	}
}

int ct_members (int a, vi &p, vi &r)
{
	int rt_a = find_set_ufds (a, p, r);
	int len = p.size ();
	int ct = 0;

	for (int i = 0; i < len; i++)
		if (find_set_ufds (i, p, r) == rt_a)
			ct++;

	return ct;
}

int
main ()
{
	int N, M;
	while (scanf ("%d %d", &N, &M), N || M) {
		vi p (N), r (N);
		bool valid = false;

		init_ufds (p, r);
		for (int i = 0; i < M; i++) {
			int c;
			scanf ("%d", &c);

			//printf ("[%d]\n", c);
			if (c > 0) {
				int rt;
				scanf ("%d", &rt);
				
				if (rt == 0)
					valid = true;
				
				for (int j = 1; j < c; j++) {
					int num;
					scanf ("%d", &num);
					if (num == 0)
						valid = true;

					union_ufds (rt, num, p, r);
				}
			}
		}
	
		
		/*
		int l = p.size ();
		printf ("[ ");
		for (int i = 0; i < l; i++) {
			printf ("%d ", p[i]);
		}
		printf ("]\n");
		*/

		if (!valid)
			printf ("1\n");
		else
			printf ("%d\n", ct_members (0, p, r));
	}

	return 0;
}

