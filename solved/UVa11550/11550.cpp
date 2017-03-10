#include <bits/stdc++.h>
using namespace std;

#define MAXN 8
#define MAXM 100

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N, M;
		scanf ("%d %d", &N, &M);

		vector<int> ct (M, 0);
		vector<int> conf (M, 0);

		bool valid = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				int num;
				scanf ("%d", &num);
				if (num == 1) {
					ct[j]++;
				
					if (ct[j] == 1)
						conf[j] = i;
					else if (ct[j] == 2)
						conf[j] = conf[j]*100 + i;
					else
						valid = false;
				}
			}
		
		for (int i = 0; i < M; i++) {
			if (ct[i] != 2) {
				valid = false;
				break;
			}
		}

		if (valid) {
			sort (conf.begin (), conf.end ());
			vector<int>::iterator it;
			
			for (it = conf.begin (); it != conf.end () && *it == 0; it++);
				//printf ("[%d]", *it);
			//printf ("\n");
		
			if (it != conf.end ()) {
				int prev = *(it++);
				for (; it != conf.end (); it++) {
					if (*it == prev) {
						valid = false;
						break;
					}
					//printf ("[%d]", *it);
					prev = *it;
				}
			}
			//printf ("\n");
		}

		if (valid)
			printf ("Yes\n");
		else
			printf ("No\n");

	}

	return 0;
}
