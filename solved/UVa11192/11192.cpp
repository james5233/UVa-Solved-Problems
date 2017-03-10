#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;

#define  MAXSTR 150

int
main ()
{
	int N;
	while (scanf (" %d", &N), N) {
		char str[MAXSTR];
		int st, end, l, n;
		scanf (" %n%s%n", &st, str, &end);
		l = end - st;
		n = l / N;

		vc stk;
		string  s = "";
		int i;
		for (i = 0; str[i] != '\0'; i++) {
			if (i % n == 0) {
				while (stk.size()) {
					char c = stk.back ();
					stk.pop_back ();

					s += c;
				}
			}

			stk.push_back (str[i]);
		}
		if (i % n == 0) {
			while (stk.size()) {
				char c = stk.back ();
				stk.pop_back ();

				s += c;
			}
		}

		puts (s.c_str ());
	}

	return 0;
}
