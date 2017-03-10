#include <bits/stdc++.h>
using namespace std;

#define BASE 100
#define MAXLINE 100009

int
main ()
{
	unsigned char arr[BASE];
	char prog[MAXLINE];
	int T;

	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf (" %s", prog);

		for (int i = 0; i < BASE; i++)
			arr[i] = 0;

		int pos = 0;

		for (char *p = prog; *p; p++) {
			if (*p == '>')
				pos = (pos + 1) % BASE;
			else if (*p == '<')
				pos = (pos - 1 + BASE) % BASE;
			else if (*p == '+')
				arr[pos]++;
			else if (*p == '-')
				arr[pos]--;
		}

		printf ("Case %d:", t);

		for (int i = 0; i < BASE; i++)
			printf (" %02X", arr[i]);

		printf ("\n");
	}

	return 0;
}
