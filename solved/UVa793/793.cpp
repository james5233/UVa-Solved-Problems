#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 100

int root_ufds (int a, vector<int> &p, vector<int> &r)
{
	return (p[a] = ((p[a] == a) ? a : root_ufds (p[a], p, r)));
}

void union_ufds (int a, int b, vector<int> &p, vector<int> &r)
{
	int ra = root_ufds (a, p, r);
	int rb = root_ufds (b, p, r);

	if (ra == rb)
		return;

	if (r[ra] > r[rb])
		p[rb] = ra;
	else {
		p[ra] = rb;
		if (r[ra] == r[rb])
			r[rb]++;
	}
}


int
main ()
{
	int T;
	for (scanf ("%d ", &T); T--;) {
		int N;
		scanf ("%d", &N);
		scanf ("%*[^\n]");
		getchar ();
		//printf ("N = %d\n", N);

		vector<int> par(N + 1), rank (N + 1);
		for (int i = 1; i <= N; i++) {
			par[i] = i;
			rank[i] = 0;
		}
		
		int c_succ, c_fail;
		char line[MAXLLEN];
		
		c_succ = c_fail = 0;
		
		while (fgets (line, MAXLLEN, stdin) && *line != '\n') {
			char act;
			int a, b;
			
			//printf ("[%s]", line);
			sscanf (line, "%c %d %d", &act, &a, &b);
			if (act == 'c')
				union_ufds (a, b, par, rank);
			else if (act == 'q') {
				int ra = root_ufds (a, par, rank);
				int rb = root_ufds (b, par, rank);

				if (ra == rb)
					c_succ++;
				else
					c_fail++;
			}
		}

		printf ("%d,%d\n", c_succ, c_fail);

		if (T)
			printf ("\n");
	}

	return 0;
}
