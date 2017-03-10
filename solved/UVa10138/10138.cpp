#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<piii> vpiii;
typedef vector<vpiii> vvpiii;

#define ENTER 0
#define EXIT 1
#define STR2ACTION(s) ((s == "enter") ? ENTER : EXIT)

#define MK_TRIPLE(x, y, z) make_pair (x, make_pair (y, z))
#define TIME(x) ((x).first)
#define ACTION(x) ((x).second.first)
#define POS(x) ((x).second.second)

int main() {
	int T;
	cin >> T;
	scanf (" ");
	
	while (T--) {
		int rate[24];
		map<string, int> ind;
		vvpiii store;
		int n_plates = 0;
		
		for (int i = 0; i < 24; i++) {
			cin >> rate[i];
			D( cout << "DEBUG: " << rate[i] << endl; )
		}
		
		scanf ("%*[^\n]");
		getchar ();
		
		string plate;
		char str[50];
		int st, end;
		st = end = 0;
		while (scanf ("%n%[^\n ]%n", &st, str, &end) == 1) {
			plate = (st != end) ? string (str) : "";
			st = end = 0;
			D( cout << "DEBUG: " << "[" << plate << "]" << endl; )
			if (plate == "")
				break;
		
			string tm, action;
			int pos;
			
			cin >> tm >> action >> pos;
			scanf ("%*[^\n]");
			getchar ();
			
			D( cout << "DEBUG: " << tm << " " << action << " " << pos << endl; )
			int MM, dd, hh, mm;
			sscanf (tm.c_str (), "%d:%d:%d:%d", &MM, &dd, &hh, &mm);
			int res = mm + 100*(hh + 100*(dd + 100*MM));
			D( cout << "DEBUG: " << "res = " << res << ";\t"; )
			map<string, int>::iterator it;
			int n;
			if ((it = ind.find (plate)) == ind.end ()) {
				ind[plate] = (n = n_plates++);
				store.push_back (vpiii ());
			} else {
				n = it->second;
			}
			
			store[n].push_back (MK_TRIPLE (res, STR2ACTION(action), pos));
			D( cout << "DEBUG: " << res << " " << action << " " << pos << endl; )
		}
		
		map<string, int>::iterator it;
		for (it = ind.begin (); it != ind.end (); it++) {
			int i = it->second;
			sort (store[i].begin (), store[i].end ());
			int len = store[i].size ();
			int cost = 0;
			int n_trips = 0;
			int j = 0;
			while (j < len) {
				D( cout << "DEBUG: " << ACTION (store[i][j]) << endl; )
				if (ACTION (store[i][j]) == EXIT) {
					j++;
				} else if (j + 1 < len) {
					if (ACTION (store[i][j + 1]) == ENTER) {
						j++;
					} else {
						int tm = TIME (store[i][j]);
						int hh = (tm % 10000) / 100;
						int rt = rate[hh];
						
						int dist = abs( POS (store[i][j+1]) - POS (store[i][j]));
						cost += dist * rt;
						n_trips++;
						j += 2;
					}
				} else
				 break;
			}
			
			if (n_trips) {
				cost += 100 * n_trips + 200;
				printf ("%s $%d.%02d\n", it->first.c_str (), cost/100, cost%100);
			}
		}
		if (T)
			cout << endl;
	}
	
	return 0;
}
