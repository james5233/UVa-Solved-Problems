#include <bits/stdc++.h>

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		char str[20];
		int st, end, l;
		scanf (" %n%s%n", &st, str, &end);
		l = end - st;
		
		if (l == 5)
			printf ("3\n");
		else if (((str[0] == 'o') + (str[1] == 'n') + (str[2] == 'e')) >= 2)
			printf ("1\n");
		else
			printf ("2\n");
	}

	return 0;
}
