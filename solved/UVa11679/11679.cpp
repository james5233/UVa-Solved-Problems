#include <bits/stdc++.h>

#define MAX_BANKS 50

int
main ()
{
	int n_banks, n_debentures;

	while (scanf ("%d%d", &n_banks, &n_debentures), 
	(n_banks || n_debentures)) {
		int reserve[MAX_BANKS];

		for (int b = 1; b <= n_banks; b++)
			scanf ("%d", reserve + b);

		for (int d = 1; d <= n_debentures; d++) {
			int debtor, creditor, value;
			scanf ("%d%d%d", &debtor, &creditor, &value);

			reserve[debtor] -= value;
			reserve[creditor] += value;
		}
		
		int b;
		for (b = 1; b <= n_banks && reserve[b] >= 0; b++);

		if (b > n_banks)
			printf ("S\n");
		else
			printf ("N\n");
	}

	return 0;
}

