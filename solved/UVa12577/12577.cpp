#include <bits/stdc++.h>

int
main ()
{
	char cmd[20];
	int case_num = 0;

	while (scanf (" %s", cmd), (*cmd != '*')) {
		case_num++;

		if (!strcmp (cmd, "Hajj"))
			printf ("Case %d: Hajj-e-Akbar\n", case_num);
		else
			printf ("Case %d: Hajj-e-Asghar\n", case_num);
	}

	return 0;
}
