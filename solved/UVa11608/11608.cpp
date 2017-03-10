#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int st, case_no;
	
	case_no = 0;
	while (scanf ("%d", &st), st >= 0) {
		vector<int> prod, req;

		for (int i = 0; i < 12; i++) {
			int n;
			scanf ("%d", &n);
			prod.push_back (n);
		}
		
		for (int i = 0; i < 12; i++) {
			int n;
			scanf ("%d", &n);
			req.push_back (n);
		}
		
		printf ("Case %d:\n", ++case_no);
		for (int i = 0; i < 12; i++) {
			if (st < req[i])
				printf ("No problem. :(\n");
			else {
				printf ("No problem! :D\n");
				st -= req[i];
			}

			st += prod[i];
		}
	}

	return 0;
}
