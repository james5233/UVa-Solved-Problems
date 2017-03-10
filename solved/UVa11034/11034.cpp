#include <bits/stdc++.h>
using namespace std;

#define LEFT 0
#define RIGHT 1

int
main ()
{
	int T;
	for (cin >> T; T--;) {
		int l, m;
		cin >> l >> m;
		l *= 100;

		queue<int> q[2];
		for (int i = 0; i < m; i++) {
			int len;
			string s;
			cin >> len >> s;

			q[(s == "left") ? LEFT : RIGHT].push (len);
		}

		int side = LEFT;
		int n_trips = 0;
		while (true) {
			if (q[side].empty ()) {
				if (q[!side].empty ()) {
					break;
				} else {
					side = !side;
					n_trips++;
				}
			} else {
				int len = 0;
				while (!q[side].empty ()) {
					if (len + q[side].front () <= l) {
						len += q[side].front ();
						q[side].pop ();
					} else
						break;
				}

				n_trips++;
				side = !side;
			}
		}

		cout << n_trips << endl;
	}

	return 0;
}

