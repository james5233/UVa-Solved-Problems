#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define LEFT 0
#define RIGHT 1

int
main ()
{
	int T;
	for (cin >> T; T--;) {
		int n, t, m;
		cin >> n >> t >> m;

		vector<int> tm;
		vector<int> dirn;
		queue<int> q[2];
		vector<int> res (m);

		for (int i = 0; i < m; i++) {
			int arvl;
			string s;
			cin >> arvl >> s;
			D( cout << "arvl = " << arvl << "s = [" << s << "]" << endl; )
			tm.push_back (arvl);
			dirn.push_back ((s == "left") ? LEFT : RIGHT);
		}

		int glob_tm = 0;
		bool side = LEFT;
		int i = 0;
		while (true) {
			while (i < m && tm[i] <= glob_tm) {
				q[(dirn[i] == LEFT) ? LEFT : RIGHT].push (i);
				i++;
			}
			
			if (q[side].empty () && !q[!side].empty ()) {
				glob_tm += t;
				side = !side;
			} else if (q[side].empty () && q[!side].empty ()) {
				if (i < m)
					glob_tm = tm[i];
				else
					break;
			} else {
				int r = 0;
				while (r < n && !q[side].empty ()) {
					res[q[side].front ()] = glob_tm + t;
					q[side].pop ();
					r++;
				}
				
				glob_tm += t;
				side = !side;
			}
		}

		for (i = 0; i < m; i++)
			cout << res[i] << endl;

		if (T)
			cout << endl;
	}

	return 0;
}




