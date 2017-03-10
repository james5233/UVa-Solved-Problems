#include <bits/stdc++.h>

#define MAX_STR 1000

int main ()
{
	int T;
	char line[MAX_STR];
	for (scanf ("%d ", &T); T--;) {
		gets (line);

		int males, females;
		char *p;

		p = line;
		males = females = 0;
		while (*p) {
			if (*p == 'M')
				males++;
			else if (*p == 'F')
				females++;

			p++;
		}

		if (males == females && males > 1)
			printf ("LOOP\n");
		else
			printf ("NO LOOP\n");
	}

	return 0;
}

