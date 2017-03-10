#include <bits/stdc++.h>
using namespace std;

#define MODDIFF(x, y) (((x) > (y)) ? ((x) - (y)) : ((y) - (x)))

int
main ()
{
	int T;

	for (scanf ("%d", &T); T--;) {
		int N, M;
		int num;

		scanf ("%d%d", &N, &M);
		map<int, int> alice, bob;
		map<int, int>::iterator it, f;

		for (int i = 0; i < N; i++) {
			scanf ("%d", &num);
			alice[num]++;
		}

		for (int i = 0; i < M; i++) {
			scanf ("%d", &num);
			bob[num]++;
		}

		int ct = 0;
		for (it = alice.begin (); it != alice.end (); it++) {
			num = it->first;

			f = bob.find (num);
			if (f == bob.end ()) {
				//printf ("num = %d; Adding %d to ct\n", num, it->second);
				ct += it->second;
			} else {
				int mdiff = MODDIFF (it->second, f->second);
				//printf ("num = %d; Adding %d to ct\n", num, mdiff);
				ct += mdiff;
				f->second = it->second = 0;
			}
		}
		
		for (it = bob.begin (); it != bob.end (); it++) {
			num = it->first;

			f = alice.find (num);
			if (f == alice.end ()) {
				//printf ("num = %d; Adding %d to ct\n", num, it->second);
				ct += it->second;
			} else {
				int mdiff = MODDIFF (it->second, f->second);
				//printf ("num = %d; Adding %d to ct\n", num, mdiff);
				ct += mdiff;
				f->second = it->second = 0;
			}
		}

		printf ("%d\n", ct);
	}

	return 0;
}
