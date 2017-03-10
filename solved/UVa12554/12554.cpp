#include <bits/stdc++.h>

#define MAX_N 120
#define MAX_STR 120

int
main ()
{
	int N;
	scanf ("%d", &N);

	char name[MAX_N][MAX_STR];
	const char *poem[] = { "Happy", "birthday", "to", "you",
                   "Happy", "birthday", "to", "you", 
	                 "Happy", "birthday", "to", "Rujia", 
                   "Happy", "birthday", "to", "you" };

	for (int n = 0; n < N; n++)
		scanf (" %s", name[n]);

	int times, person, word;
	
	times = 16 * ((N + 15)/16);
	person = word = 0;

	for (int i = 0; i < times; i++) {
		printf ("%s: %s\n", name[person], poem[word]);
		person = (person + 1) % N;
		word = (word + 1) % 16;
	}

	return 0;
}
