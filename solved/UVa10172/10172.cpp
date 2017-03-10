#include <bits/stdc++.h>
using namespace std;

typedef queue<unsigned int> qi;
typedef vector<qi> vqi;
typedef stack<unsigned int> si;

int
main ()
{
	unsigned int T;
	for (cin >> T; T--;) {
		unsigned int N, S, Q;
		cin >> N >> S >> Q;

		vqi st (N + 1);
		si stk;
		
		unsigned int n_pkg = 0;
		for (unsigned int n = 1; n <= N; n++) {
			unsigned int sz;
			cin >> sz;

			n_pkg += sz;

			for (unsigned int i = 0; i < sz; i++) {
				unsigned int id;
				cin >> id;
				st[n].push (id);
			}
		}
		
		unsigned int n = 1;
		unsigned int tm = 0;
		while (true) {
			/* Unloading Phase */
			while (stk.size ()) {
				if (stk.top () == n) {
					stk.pop ();
					n_pkg--;
					tm += 1;
				} else if (st[n].size () < Q) {
					st[n].push (stk.top ());
					stk.pop ();
					tm += 1;
				} else {
					break;
				}
			}
			
			/* Loading Phase */
			while (stk.size () < S && !st[n].empty ()) {
				stk.push (st[n].front ());
				st[n].pop ();
				tm += 1;
			}
			
			/* Decide whether we're all done or move to next station */
			if (n_pkg > 0) {
				n = n % N + 1;
				tm += 2;
			} else {
				break;
			}
		}

		cout << tm << endl;
	}

	return 0;
}

