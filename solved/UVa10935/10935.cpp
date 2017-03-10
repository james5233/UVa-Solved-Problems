#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	while ((cin >> N), N) {
		list<int> lst;

		for (int i = 1; i <= N; i++)
			lst.push_back (i);
		
		cout << "Discarded cards:";

		if (N > 1) {
			cout << " 1";
			lst.pop_front ();
			lst.pop_front ();
			lst.push_back (2);
			N--;

			while (N > 1) {
				cout << ", " << lst.front ();
				lst.pop_front ();
				lst.push_back (lst.front ());
				lst.pop_front ();
				N--;
			}
		}

		cout << endl;
		cout << "Remaining card: " << lst.front () << endl;
	}

	return 0;
}

