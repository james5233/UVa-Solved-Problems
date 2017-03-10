#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 500

int
main ()
{
	int T;

	for (scanf ("%d ", &T); T--;) {
		char line[MAXLLEN];
		
		fgets (line, MAXLLEN, stdin);
		line[strcspn (line, "\n")] = 0;
		
		string binder = line;
		
		unordered_map<string, int> price;
		vector< pair<int, string> > recepie;
		
		int m, n, b;
		scanf ("%d %d %d ", &m, &n, &b);
		
		for (int i = 0; i < m; i++) {
			char ingredient[MAXLLEN];
			int cost;
			fgets (line, MAXLLEN, stdin);
			sscanf (line, "%s %d", ingredient, &cost);
			
			price[ingredient] = cost;
		}

		for (int i = 0; i < n; i++) {
			fgets (line, MAXLLEN, stdin);
			line[ strcspn (line, "\n") ] = 0;

			string r = line;
			int cost = 0;
			
			int k;
			scanf ("%d ", &k);
			for (int j = 0; j < k; j++) {
				char ing[MAXLLEN];
				int qty;
				fgets (line, MAXLLEN, stdin);
				sscanf (line, "%s %d", ing, &qty);
				cost += qty * price[ing];
			}
			
			if (cost <= b)
				recepie.push_back (make_pair (cost, r));

		}

		sort (recepie.begin (), recepie.end ());
		string::iterator it;
		
		for (it = binder.begin (); it != binder.end (); it++)
			*it = toupper (*it);

		printf ("%s\n", binder.c_str ());

		int l = recepie.size ();
		if (!l)
			printf ("Too expensive!\n");
		else {
			for (int j = 0; j < l; j++)
				printf ("%s\n", recepie[j].second.c_str ());
		}

		printf ("\n");
	}

	return 0;
}



	
