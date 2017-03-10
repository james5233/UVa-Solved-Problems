#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N;
		scanf ("%d", &N);

		unordered_map<int, int> ind;
		int prev_len = 0;
		int max_len = 0;

		for (int i = 0; i < N; i++) {
			int num;
			int len_pos;

			scanf ("%d", &num);

			unordered_map<int, int>::iterator it = ind.find (num);
			if (it == ind.end ()) {
				len_pos = i + 1;
				ind[num] = i;
			} else {
				len_pos = i - it->second;
				it->second = i;
			}

			int cur = min (len_pos, prev_len + 1);
			if (cur > max_len)
				max_len = cur;

			prev_len = cur;
		}

		printf ("%d\n", max_len);
	}

	return 0;
}

