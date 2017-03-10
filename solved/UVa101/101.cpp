#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

typedef struct block_t {
	int pos;
	int top;
} block_t;

#define MAXN 30

int
main ()
{
	int N;
	scanf ("%d", &N);
	vector<block_t> p (N);

	for (int i = 0; i < N; i++) {
		p[i].pos = i;
		p[i].top = -1;
	}
	
	char cmd[20];
	while (scanf (" %s", cmd), strcmp (cmd, "quit")) {
		char action[10];
		int a, b;

		scanf ("%d %s %d", &a, action, &b);
		if (p[a].pos == p[b].pos)
			continue;

		if (!strcmp (cmd, "move")) {
			int t = p[a].top;

			while (t != -1) {
				int sav = p[t].top;

				p[t].pos = t;
				p[t].top = -1;

				t = sav;
			}

			p[a].top = -1;
		}

		if (!strcmp (action, "onto")) {
			int t = p[b].top;
			while (t != -1) {
				int sav = p[t].top;

				p[t].pos = t;
				p[t].top = -1;

				t = sav;
			}

			p[b].top = -1;
		}


		int r = b;
		while (p[r].top != -1)
			r = p[r].top;
		
		if (a != p[a].pos) {
			int l = p[a].pos;
			while (p[l].top != a)
				l = p[l].top;

			p[l].top = -1;
		}
		
		for (int t = a; t != -1; t = p[t].top)
			p[t].pos = p[b].pos;

		p[r].top = a;
		
		D( printf ("[%s %d %s %d]\n", cmd, a, action, b);

		for (int i = 0; i < N; i++) {
			printf ("%d:", i);

			if (p[i].pos == i) {
				int t = i;

				while (t != -1) {
					printf (" %d", t);
					t = p[t].top;
				}
			}
			printf ("\n");
		}
		)
	}

	D( printf ("[quit]\n");)
	for (int i = 0; i < N; i++) {
		printf ("%d:", i);

		if (p[i].pos == i) {
			int t = i;

			while (t != -1) {
				printf (" %d", t);
				t = p[t].top;
			}
		}
		printf ("\n");
	}

	return 0;
}
