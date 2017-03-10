#include <bits/stdc++.h>
using namespace std;

int main ()
{
	char c;
	long st, end, l;

	st = end = -1L;

	while (scanf (" %ln%c%*[^\n]%ln", &st, &c, &end), c != 'E') {
		if (end < 0)
			l = 1;
		else
			l = end - st;

		if (l == 1 && c == '1')
			printf ("1\n");
		else {
			long x_old = l;
			int i = 2;

			while (1) {
				l = x_old;

				long x_new = 0;
				do {
					l /= 10;
					x_new++;
				} while (l);

				if (x_old == x_new) {
					printf ("%d\n", i);
					break;
				}

				x_old = x_new;
				i++;
			}
		}

		st = end = -1L;
	}

	return 0;
}
