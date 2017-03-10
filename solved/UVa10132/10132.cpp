#include <bits/stdc++.h>
using namespace std;

#define MAXSZ 256

int
main ()
{
	int T;
	string s;
	cin >> T;
	scanf (" ");
	
	while (T--) {
		vector<string> v [MAXSZ + 1];
		unordered_map<string, int> mp;

		int max_len = 0, min_len = INT_MAX;
		while (getline (cin, s)) {
			//cout << "DEBUG: [" << s << "]" << endl;
			if (s.empty ())
				break;

			int len = s.length ();
			max_len = max (max_len, len);
			min_len = min (min_len, len);

			v[len].push_back (s);
		}

		int B = max_len + min_len;

		for (int i = 1; i <= MAXSZ/2; i++) {
			if (v[i].empty ())
				continue;
			else if (v[B - i].empty ())
				continue;
			
			vector<string>::iterator s, l;

			for (s = v[i].begin (); s != v[i].end (); s++)
				for (l = v[B - i].begin (); l != v[B - i].end (); l++) {
					mp[*s + *l]++;
					mp[*l + *s]++;
				}
		}

		unordered_map<string, int>::iterator it;
		int M = 0;
		
		for (it  = mp.begin (); it != mp.end (); it++) {
			if (it->second > M) {
				M = it->second;
				s = it->first;
			}
		}

		cout  << s << endl;
		if (T)
			cout << endl;
	}

	return 0;
}


