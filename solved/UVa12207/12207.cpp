#include <bits/stdc++.h>
using namespace std;

#define MAXC 1001

typedef list<long> li;

int
main ()
{
	long P, C, case_no = 0;
	while ((cin >> P >> C), (P || C)) {
		vector<li::iterator> v (C + 1);
		li lst;
		
		long lim = min (C, P);
		for (long id = 1; id <= lim; id++)
			v[id] = lst.insert (lst.end (), id);
		
		cout << "Case " << ++case_no << ":" << endl;
		for (long i = 0; i < C; i++) {
			string s;
			long id;

			cin >> s;

			if (s == "N") {
				id = lst.front ();

				if (id <= lim)
					v[id] = lst.insert (lst.end (), id);
				
				lst.pop_front ();
				cout << id << endl;
			} else {
				cin >> id;
				long f = lst.front ();

				if (id <= lim) {
					lst.erase (v[id]);
 					v[id] = lst.insert (lst.begin (), id);
				} else if (f != id) {
					lst.insert (lst.begin (), id);
				}
			}
		}
	}

	return 0;
}

