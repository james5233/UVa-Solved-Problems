#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	map<int, int> ct;
	vector<int> rank;

	int num;
	while (scanf ("%d", &num) == 1) {
		map<int, int>::iterator it;
		if ((it = ct.find (num)) != ct.end ()) {
			it->second++;
		} else {
			ct[num] = 1;
			rank.push_back (num);
		}
	}

	vector<int>::iterator iter;
	for (iter = rank.begin (); iter != rank.end (); iter++) {
		printf ("%d %d\n", *iter, ct[*iter]);
	}

	return 0;
}

