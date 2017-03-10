#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef list<pii> lpii;
typedef unordered_map<int, int> umapii;

int
main ()
{
	int n_teams, case_no = 0;
	while (scanf ("%d", &n_teams), n_teams) {
		vector< lpii::iterator > pos (n_teams);
		vector<bool> valid (n_teams, false);
		lpii lst;
		umapii mp;

		for (int i = 0; i < n_teams; i++) {
			int n_memb;
			scanf ("%d", &n_memb);

			for (int j = 0; j < n_memb; j++) {
				int num;
				scanf ("%d", &num);
				mp[num] = i;
			}
		}
		
		printf ("Scenario #%d\n", ++case_no);
		char cmd[20];
		while (scanf (" %s", cmd), strcmp (cmd, "STOP")) {
			if (!strcmp (cmd, "ENQUEUE")) {
				int num;
				scanf ("%d",&num);
				int team = mp[num];
				pii p = make_pair (num, team);
				lpii::iterator it = pos[team];

				if (valid[team])
					pos[team] = lst.insert (++it, p);
				else {
					pos[team] = lst.insert (lst.end (), p);
					valid[team] = true;
				}
			} else if (lst.size ()) {
				lpii::iterator p = lst.begin ();
				int team = p->second;

				if (pos[team] == p) {
					valid[team] = false;
				}

				printf ("%d\n", p->first);
				lst.pop_front ();
			}
		}

		printf ("\n");
	}

	return 0;
}
