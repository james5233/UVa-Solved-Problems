#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<string, long> umapsl_t;
typedef pair<string, string> pss;
typedef vector<pss> vpss;

#define MAX_STR 100
#define MAXLINE 200

int
main ()
{
	vpss v;
	umapsl_t haha;

	char author[MAX_STR];
	char title[MAX_STR];
	int n_books = 0;

	while (scanf (" \"%[^\"]\" by %[^\n]", title, author) == 2) {
		v.push_back (make_pair (author, title));
		/*printf ("read %s\n", title);*/
		n_books++;
	}

	sort (v.begin (), v.end ());

	for (int i = 0; i < n_books; i++)
		haha[v[i].second] = i;

	scanf (" %*[^\n]");

	vector<bool> returned (n_books, false);
	vector<bool> on_shelf (n_books, true);
	int n_returned = 0;	

	char cmd[MAX_STR];
	while (scanf (" %s", cmd), strcmp (cmd, "END") != 0) {
		/*printf ("Command is %s\n", cmd);*/
		if (!strcmp (cmd, "BORROW")) {
			scanf (" \"%[^\"]\"", title);
			on_shelf[haha[title]] = false;
		} else if (!strcmp (cmd, "RETURN")) {
			scanf (" \"%[^\"]\"", title);
			returned[haha[title]] = true;
			n_returned--;
		} else {
			int b;
			int before = -1;

			for (b = 0; b < n_books; b++) {
				if (on_shelf[b])
					before = b;

				if (returned[b]) {

					if (before < 0) 
						printf ("Put \"%s\" first\n", v[b].second.c_str ());
					else 
						printf ("Put \"%s\" after \"%s\"\n",
											v[b].second.c_str (), v[before].second.c_str ());
					returned[b] = false;
					on_shelf[b] = true;
					before = b;
				}
			}
			
			n_returned = 0;
			printf ("END\n");
		}
	}
	
	return 0;
}
