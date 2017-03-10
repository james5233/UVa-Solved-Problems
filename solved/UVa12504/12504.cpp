#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 200

int
main ()
{
	int T;

	for (scanf ("%d ", &T); T--;) {
		char line[MAXLLEN], *p, *tok;
		unordered_map<string, string> dict;
		vector<string> added, removed, changed;

		fgets (line, MAXLLEN, stdin);
		line[ strcspn (line, "}")] = 0;
		for (p = line; *(p++) != '{';);

		while ((tok = strsep (&p, ",}")) && *tok) {
			char key[MAXLLEN], val[MAXLLEN];
			sscanf (tok, "%[^:]:%[^:]", key, val);
			dict[key] = val;
		}

		fgets (line, MAXLLEN, stdin);
		line[ strcspn (line, "}")] = 0;
		for (p = line; *(p++) != '{';);

		while ((tok = strsep (&p, ",}")) && *tok) {
			char key[MAXLLEN], val[MAXLLEN];
			sscanf (tok, "%[^:]:%[^:]", key, val);
			
			unordered_map<string, string>::iterator it = dict.find (key);
			if (it == dict.end ()) {
				added.push_back (key);
			} else if (it->second != string (val)) {
				changed.push_back (key);
				it->second = "+";
			} else {
				it->second = "+";
			}
		}

		unordered_map<string, string>::iterator it;
		for (it = dict.begin (); it != dict.end (); it++) {
			if (it->second != "+")
				removed.push_back (it->first);
		}

		sort (added.begin (), added.end ());
		sort (removed.begin (), removed.end ());
		sort (changed.begin (), changed.end ());

		int a = added.size ();
		int r = removed.size ();
		int c = changed.size ();

		if (a + r + c == 0)
			printf ("No changes\n");
		else {
			if (a > 0) {
				printf ("+%s", added[0].c_str ());
				for (int i = 1; i < a; i++)
					printf (",%s", added[i].c_str ());
				printf ("\n");
			}
			
			if (r > 0) {
				printf ("-%s", removed[0].c_str ());
				for (int i = 1; i < r; i++)
					printf (",%s", removed[i].c_str ());
				printf ("\n");
			}
		
			if (c > 0) {
				printf ("*%s", changed[0].c_str ());
				for (int i = 1; i < c; i++)
					printf (",%s", changed[i].c_str ());
				printf ("\n");
			}
		}

		printf ("\n");
	}

	return 0;
}
