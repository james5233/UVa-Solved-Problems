#include <bits/stdc++.h>

#define MAXLEN 10000

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		char str[MAXLEN];
		int st, end, l;
		scanf (" %n%s%n", &st, str, &end);
		l = end - st;

		if (!strcmp (str, "1") || !strcmp (str, "4") || !strcmp (str, "78"))
			printf ("+\n");
		else if (!strcmp (str + l - 2, "35"))
			printf ("-\n");
		else if (*str == '9' && *(str + l - 1) == '4')
			printf ("*\n");
		else
			printf ("?\n");
	}

	return 0;
}

