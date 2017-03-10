#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define MAXLLEN 2000

int
main ()
{
	char line[MAXLLEN];
	vector<string> org;
	vector<int> ct;
	int n_orgs;
	unordered_map<string, int> stud_pref;

	while (fgets (line, MAXLLEN, stdin) && (*line != '0')) {
		if (*line == '1') {
			vector<pair< int, string> >p;

			for (int i = 0; i < n_orgs; i++)
				p.push_back (make_pair (-ct[i], org[i]));

			sort (p.begin (), p.end ());
			vector< pair<int, string> >::iterator it;
			for (it = p.begin (); it != p.end (); it++)
				printf ("%s %d\n", it->second.c_str (), -(it->first));

			n_orgs = 0;
			org.clear ();
			ct.clear ();
			stud_pref.clear ();
		} else {
			line[ strcspn (line, "\n") ] = 0;
			D( puts (line); )

			int is_org = 0;
			char *p;
			for (p = line; *p && (*p < 'A' || *p > 'Z'); p++);
			if (*p)
				is_org = 1;

			if (is_org) {
				D( printf ("Organisation : *p = %c\n", *p); )
				org.push_back (line);
				ct.push_back (0);
				n_orgs++;
			} else {
				unordered_map<string, int>::iterator it = stud_pref.find (line);

				if (it == stud_pref.end ()) {
					stud_pref[line] = n_orgs - 1;
					ct[n_orgs - 1]++;
				} else {
					if (it->second >= 0 && it->second != n_orgs - 1) {
						ct[it->second]--;
						stud_pref[line] = -1;
					}
				}
			}
		}
	}

	return 0;
}





