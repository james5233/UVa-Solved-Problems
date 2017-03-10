#include <bits/stdc++.h>

#define MAXSTR 30

int
main ()
{
	char str[MAXSTR];
	int st, end, l;

	while (scanf (" %n%s%n", &st, str, &end), 
				 !(((l = end - st) == 1) && (*str == '0'))) {
		char *p = str;
		int digsum = 0;
		while (*p) {
			digsum += *(p++) - '0';

			if (digsum >= 10)
				digsum = digsum/10 + digsum%10;
		}

		printf ("%d\n", digsum);
	}

	return 0;
}
