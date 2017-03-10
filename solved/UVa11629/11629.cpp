#include <bits/stdc++.h>
using namespace std;

#define MAXNAMELEN 25
#define MAXLLEN 2000

int
main ()
{
	int N, G;
	scanf ("%d %d ", &N, &G);

	unordered_map<string, int> votes;
	char line[MAXLLEN], name[MAXNAMELEN], sep[5];

	for (int i = 0; i < N; i++) {
		fgets (line, MAXLLEN, stdin);

		int num, den;
		sscanf (line, "%s %d.%d", name, &num, &den);
		votes[name] = num * 10 + den;
	}

	for (int i = 1; i <= G; i++) {
		fgets (line, MAXLLEN, stdin);
		char *p = line;
		int len;
		int sum = 0;
		
		do {
			len = 0;
			sscanf (p, "%s %s%n", name, sep, &len);
			sum += votes[name];
			p += len;
		} while (*sep == '+');
		
		int num;
		sscanf (p, "%d", &num);
		num *= 10;

		bool correct = (!strcmp (sep, "<") && sum < num) ||
									(!strcmp (sep, "<=") && sum <= num) ||
									(!strcmp (sep, "=") && sum == num) ||
									(!strcmp (sep, ">") && sum > num) ||
									(!strcmp (sep, ">=") && sum >= num);

		if (correct)
			printf ("Guess #%d was correct.\n", i);
		else
			printf ("Guess #%d was incorrect.\n", i);
	}

	return 0;
}





