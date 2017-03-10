#include <bits/stdc++.h>

int
main ()
{
	int T;
	long sum = 0L;

	for (scanf ("%d", &T); T--;) {
		char cmd[20];

		scanf (" %s", cmd);
		if (!strcmp (cmd, "donate")) {
			long donation;
			scanf ("%ld", &donation);
			sum += donation;
		} else 
			printf ("%ld\n", sum);
	}

	return 0;
}
