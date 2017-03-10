#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 20000

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N;
		scanf ("%d ", &N);
		vector<int> v;
		int min_ct = N;
		char line[MAXLLEN];

		for (int i = 0; i < N; i++) {
			fgets (line, MAXLLEN, stdin);
			int ct = 0;
			char *p = line;
			int len = 0;
			int num;

			while (!(len = 0) && sscanf (p, "%d%n", &num, &len) == 1) {
				ct++;
				p += len;
			}

			min_ct = min (min_ct, ct);
			v.push_back (ct);
		}
		
		bool first = true;
		for (int i = 0; i < N; i++) {
			if (v[i] == min_ct) {
				if (first) {
					printf ("%d", i + 1);
					first = false;
				} else 
					printf (" %d", i + 1);
			}
		}

		printf ("\n");
	}

	return 0;
}
