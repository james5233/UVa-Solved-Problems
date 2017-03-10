#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N;
		char subject[100];
		
		scanf ("%d ", &N);

		unordered_map<string, int> days;
		for (int i = 0; i < N; i++) {
			int d;
			scanf (" %s%d", subject, &d);
			days[subject] = d;
		}
		
		int D;
		scanf ("%d ", &D);
		scanf (" %s", subject);

		unordered_map<string, int>::iterator it = days.find (subject);
		if (it == days.end ()) {
			printf ("Case %d: Do your own homework!\n", t);
		} else {
			int req = it->second;
			if (req <= D)
				printf ("Case %d: Yesss\n", t);
			else if (req <= D + 5)
				printf ("Case %d: Late\n", t);
			else
				printf ("Case %d: Do your own homework!\n", t);
		}
	}

	return 0;
}
