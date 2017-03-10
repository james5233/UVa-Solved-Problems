#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;

	while (scanf ("%d", &N), N) {
		
		do {

			stack<int> A, stn;
			vector<int> B;

			for (int i = N; i > 0; i--)
				A.push (i);
			
			int num;
			scanf ("%d", &num);

			if (num == 0) {
				printf ("\n");
				break;
			}

			B.push_back (num);
			for (int i = 1; i < N; i++) {
				scanf ("%d", &num);
				B.push_back (num);
			}
			
			int i = 0;
			bool valid = true;
			while (i < N && valid) {
				int t = B[i];

				if (stn.size () && stn.top () == t) {
					stn.pop ();
					i++;
				} else if (A.size ()) {
					stn.push (A.top ());
					A.pop ();
				} else
					valid = false;
			}

			if (valid)
				printf ("Yes\n");
			else
				printf ("No\n");
		} while (true);
	}

	return 0;
}

