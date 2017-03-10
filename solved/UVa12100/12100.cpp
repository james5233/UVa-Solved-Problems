#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (cin >> T; T--;) {
		int n, m;
		cin >> n >> m;

		queue<int> q;
		vector<int> ct (10, 0);

		for (int i = 0; i < n; i++) {
			int pr;
			cin >> pr;
			q.push (pr);
			ct[pr]++;
		}
		
		int tm = 0;
		while (true) {
			int pr = q.front ();
			
			int c = 0;
			for (int p = pr + 1; p < 10; p++)
				c += ct[p];

			if (c == 0) {
				q.pop ();
				ct[pr]--;
				tm++;
				n--;

				if (m == 0)
					break;
				else
					m--;
			} else {
				q.push (pr);
				q.pop ();

				m = (m - 1 + n) % n;
			}
		}

		cout << tm << endl;
	}

	return 0;
}
