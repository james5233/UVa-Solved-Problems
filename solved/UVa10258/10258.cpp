#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<pii, int> piii;
typedef vector<piii> vpiii;
typedef vector<bool> vb;

#define N_PROBS_SOLVED(x) (-((x).first.first))
#define TIME(x) ((x).first.second)
#define USER_ID(x) ((x).second)

#define MK_TRI(x, y, z) (make_pair (make_pair (-(x), (y)), (z)))

#define MAX_USERS 101
#define MAX_PROBS 10

int
main ()
{
	int T;
	for (scanf ("%d ", &T); T--;) {
		vpii store[MAX_USERS][MAX_PROBS];
		vb submitted (MAX_USERS, false);
		vpiii lst;

		char str[200];
		int st, end;
		int status;
		while ((status = scanf ("%n%[^\n]%n", &st, str, &end)) != EOF) {
			getchar ();
			if (status != 1)
				break;
			
			int uid, probid, tm;
			char ch;

			sscanf (str, "%d %d %d %c", &uid, &probid, &tm, &ch);
			D( printf ("DEBUG: Read [%d, %d, %d, %c]\n", uid, probid, tm, ch); )
			submitted[uid] = true;

			if (ch == 'I' || ch == 'C') {
				int succ = (ch == 'C');
				store[uid][probid].push_back (make_pair (tm, succ));
			}
		}

		for (int u = 1; u < MAX_USERS; u++) {
			if (!submitted[u])
				continue;
			
			int ct_solved = 0;
			int total_tm = 0;

			for (int p = 1; p < MAX_PROBS; p++) {
				int l, i;
				if ((l = store[u][p].size ()) > 0) {
					sort (store[u][p].begin (), store[u][p].end ());
					
					for (i = 0; i < l && !(store[u][p][i].second); i++);

					if (i < l) {
						total_tm += store[u][p][i].first + 20 * i;
						ct_solved++;
					} 
				}
			}

			lst.push_back (MK_TRI (ct_solved, total_tm, u));
		}

		sort (lst.begin (), lst.end ());

		vpiii::iterator it;
		for (it  = lst.begin (); it != lst.end (); it++)
			printf ("%d %d %d\n", USER_ID (*it), N_PROBS_SOLVED (*it), TIME (*it));

		if (T)
			printf ("\n");
	}

	return 0;
}
