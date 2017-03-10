#include <bits/stdc++.h>
using namespace std;

typedef list<long> li;

int
main ()
{
	long P, C, case_no = 0;
	while ((cin >> P >> C), (P || C)) {
		li lst;
		
		long lim = min (C, P);
		for (long id = 1; id <= lim; id++)
			lst.push_back (id);
		
		cout << "Case " << ++case_no << ":" << endl;
		for (long i = 0; i < C; i++) {
			string s;
			long id;

			cin >> s;

			if (s == "N") {
				id = lst.front ();

				lst.push_back ( id);
				lst.pop_front ();
				cout << id << endl;
			} else {
				cin >> id;
				assert (id <= P);

				lst.remove (id);
				lst.push_front (id);
			}
		}
	}

	return 0;
}

