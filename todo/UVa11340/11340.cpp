#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
/*	int store[1000];
	int *v = store + 500; */

	for (scanf ("%d", &T); T--;) {
		int N;
		scanf (" %d", &N);
		scanf ("%*[^\n]");
		getchar ();
		
		unordered_map<char, int> v;

		/*for (int i = -255; i < 256; i++)
			v[i] = 0;*/

		for (int i = 0; i < N; i++) {
			char c;
			int val;
			scanf ("%c%d", &c, &val);
			scanf ("%*[^\n]");
			getchar ();
			
			v[c] = val;
		}

		int M;
		long sum = 0L;
		scanf ("%d", &M);
		scanf ("%*[^\n]");
		getchar ();

		for (int i = 0; i < M; i++) {
			char str[10100];
			scanf ("%[^\n]", str);
			getchar ();

			for (int j = 0; str[j] != '\0'; j++)
				sum += (v.find(str[j]) == v.end ()) ? 0 : v[str[j]];
		}

		printf ("%.2f$\n", sum/100.0);
	}

	return 0;
}

