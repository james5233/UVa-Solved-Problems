#include <bits/stdc++.h>
using namespace std;

#define MAXLINE 2000009L
#define POS_INFTY MAXLINE
#define NEG_INFTY (-MAXLINE)

int 
main ()
{
	long L;
	char line[MAXLINE];
	while (scanf ("%ld ", &L), L) {
		gets (line);
		long rest, drug, min_dist;

		min_dist = LONG_MAX;
		rest = NEG_INFTY;
		drug = NEG_INFTY;
		
		for (long i = 0; line[i] != '\0'; i++) {
			if (line[i] == 'R') {
				rest = i;
				long dist = rest - drug;

				if (dist < min_dist)
					min_dist = dist;
			} else if (line[i] == 'D') {
				drug = i;
				long dist = drug - rest;

				if (dist < min_dist)
					min_dist = dist;
			} else if (line[i] == 'Z') {
				min_dist = 0;
				break;
			}
		}

		printf ("%ld\n", min_dist);
	}

	return 0;
}

