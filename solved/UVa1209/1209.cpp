#include <bits/stdc++.h>
using namespace std;

#define MAXSTR 25

int
main ()
{
	char str[MAXSTR];
	int st, end;
	while (scanf (" %n%s%n", &st, str, &end) != EOF) {
		char sav[MAXSTR], res[MAXSTR];
		int max_d = 0;
		int l = end - st;

		strcpy (res, str);
		strcpy (sav, str);
		
		if (l > 1) {
			for (int i = 0; i < 11; i++) {
				int d = 27;
				for (int i = 1; i < l; i++) {
					int dc = abs (str[i] - str[i-1]);
					d = min (d, dc);
				}

				if (d > max_d) {
					max_d = d;
					strcpy (res, str);
				} else if (d == max_d && strcmp (str, res) <= 0) {
					strcpy (res, str);
				}

				next_permutation (str, str + l);
			}

			strcpy (str, sav);
			for (int i = 0; i < 10; i++) {
				prev_permutation (str, str + l);
				int d = 27;
				for (int i = 1; i < l; i++) {
					int dc = abs (str[i] - str[i-1]);
					d = min (d, dc);
				}

				if (d > max_d) {
					max_d = d;
					strcpy (res, str);
				} else if (d == max_d && strcmp (str, res) <= 0) {
					strcpy (res, str);
				}
			}
		} 

		printf ("%s%d\n", res, max_d);
	}

	return 0;
}

