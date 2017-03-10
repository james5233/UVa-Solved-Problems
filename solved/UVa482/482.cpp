#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, double> pid;
typedef pair<int, string> pis;
typedef vector<pid> vpid;
typedef vector<pis> vpis;

int
main ()
{
	int N;
	bool first = true;

	for (scanf ("%d ", &N); N--;) {

		vi ind;

		//scanf ("%*[^\n]%*c");
		int d, ct;
		char s[20];

		ct = 0;
		while (scanf ("%d%[ \n]", &d, s) == 2) {
			ind.push_back (d);
			ct++;

			if (strchr (s, '\n') != NULL)
				break;
		}

		vpis store;
		for (int i = 0; i < ct; i++) {
			char str[100];
			scanf ("%s ", str);

			store.push_back( make_pair (ind[i], string(str)));
		}
		
		sort (store.begin (), store.end ());

		if (!first) 
			printf ("\n");
		else
			first = false;

		for (int i = 0; i < ct; i++)
			printf ("%s\n", store[i].second.c_str ());
	}

	return 0;
}

			
