#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (scanf ("%d ", &T); T--;) {
		long N, M;
		scanf ("%ld%ld", &N, &M);

		vector<long> arr;
		multimap<long, int> s;

		for (int i = 0; i < N; i++) {
			long num;
			scanf ("%ld", &num);

			arr.push_back (num);
		}

		int j = 0, sz = 0;
		s.insert (make_pair (LONG_MIN, -1));
		multimap<long, int>::iterator cur = s.begin ();

		for (int i = 0; i < M; i++) {
			int pos;
			scanf ("%d", &pos);
			//printf ("Read: %d\n", pos);

			while (sz < pos) {
				long num = arr[j];
				//printf ("j = %d, arr[j] = %ld\n", j, arr[j]);
				s.insert (make_pair (num, j++));
				sz++;
				if (num < cur->first)
					cur--;
			}
			
			cur++;
			printf ("%ld\n", cur->first);
		}

		if (T)
			printf ("\n");
	}

	return 0;
}

