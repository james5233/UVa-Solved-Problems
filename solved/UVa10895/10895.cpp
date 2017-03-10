#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int
main ()
{
	int N, M;
	while (scanf ("%d %d", &N, &M) == 2) {
		vpii temp;
		vvpii v (M, temp);

		for (int i = 0; i < N; i++) {
			int r;
			vi st;
			scanf ("%d", &r);
			for (int j = 0; j < r; j++) {
				int num;
				scanf ("%d", &num);
				st.push_back (num - 1);
			}

			for (int j = 0; j < r; j++) {
				int num;
				scanf ("%d", &num);
				v[st[j]].push_back (make_pair (i, num));
			}
		}
		
		printf ("%d %d\n", M, N);
		for (int i = 0; i < M; i++) {
			int sz = v[i].size ();
			printf ("%d", sz);

			vpii::iterator it;
			for (it = v[i].begin (); it != v[i].end (); it++) {
				printf (" %d", it->first + 1);
			}
			printf ("\n");
			
			it = v[i].begin ();
			if (v[i].size ()) {
				printf ("%d", it->second);
				it++;
			}
			for (; it != v[i].end (); it++) {
				printf (" %d", it->second);
			}
			printf ("\n");
		}
	}

	return 0;
}


			

