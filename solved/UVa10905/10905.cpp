#include <bits/stdc++.h>
using namespace std;

bool cmp_str (string s1, string s2) {
	return ((s2 + s1) < (s1 + s2));
}

int
main ()
{
	int N;
	while (scanf ("%d", &N), N) {
		vector<string> s;
		
		for (int i = 0; i < N; i++) {
			char str[50];
			scanf (" %s", str);

			s.push_back (string (str));
		}

		sort (s.begin (), s.end (), cmp_str);

		vector<string>::iterator it;
		for (it = s.begin (); it != s.end (); it++)
			printf ("%s", it->c_str ());
		printf ("\n");
	}

	return 0;
}
