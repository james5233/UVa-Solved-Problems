#include <bits/stdc++.h>

#define MAXLEN 20

int
main () 
{
	char str[MAXLEN];
	int caseNO = 0;

	while (scanf (" %s", str), (*str != '#')) {
		caseNO++;

		if (!strcmp (str, "HELLO"))
			printf ("Case %d: ENGLISH\n", caseNO);
		else if (!strcmp (str, "HOLA"))
			printf ("Case %d: SPANISH\n", caseNO);
		else if (!strcmp (str, "HALLO"))
			printf ("Case %d: GERMAN\n", caseNO);
		else if (!strcmp (str, "BONJOUR"))
			printf ("Case %d: FRENCH\n", caseNO);
		else if (!strcmp (str, "CIAO"))
			printf ("Case %d: ITALIAN\n", caseNO);
		else if (!strcmp (str, "ZDRAVSTVUJTE"))
			printf ("Case %d: RUSSIAN\n", caseNO);
		else
			printf ("Case %d: UNKNOWN\n", caseNO);
	}

	return 0;
}
