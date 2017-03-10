#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 50

int
main ()
{
	int N;
	while (scanf ("%d", &N) == 1) {
		int M;
		scanf ("%d", &M);
		scanf ("%*[^\n]");
		getchar ();

		int has_edge[26][26];
		int is_valid_node[26];
		int is_awake[26];
		int ct_awake_conn[26][26];

		for (int i = 0; i < 26; i++) {
			is_valid_node[i] = is_awake[i] = 0;
			for (int j = 0; j < 26; j++) {
				has_edge[i][j] = 0;
				ct_awake_conn[i][j] = 0;
			}
		}

		char line[MAXLLEN];
		int l;
		fgets (line, MAXLLEN, stdin);
		line[l = strcspn (line, "\n")] = 0;
		
		for (int i = 0; i < l; i++)
			is_awake[line[i] - 'A'] = is_valid_node[line[i] - 'A'] = 1;

		for (int i = 0; i < M; i++) {
			int l;
			fgets (line, MAXLLEN, stdin);
			line[l = strcspn (line, "\n")] = 0;

			is_valid_node[line[0] - 'A'] = is_valid_node[line[1] - 'A'] = 1;
			has_edge[line[0] - 'A'][line[1] - 'A'] = 1;
			has_edge[line[1] - 'A'][line[0] - 'A'] = 1;
		}

		for (int i = 0; i < 26; i++) {
			if (is_awake[i]) {
				for (int j = 0; j < 26; j++) {
					if (has_edge[i][j])
						ct_awake_conn[j][i] = 1;
				}
			}
		}

		vector<int> wake_up (26, 0);
		int n_asleep = N - 3;
		int stalled = 0;
		int year = 0;

		while (n_asleep > 0 && !stalled) {
			stalled = 1;
				
			for (int i = 0; i < 26; i++) {
				if (!is_valid_node[i] || is_awake[i])
					continue;

				int nbr = accumulate (ct_awake_conn[i], ct_awake_conn[i] + 26, 0);
				if (nbr >= 3) {
					wake_up[i] = 1;
					stalled = 0;
				}
			}

			for (int i = 0; i < 26; i++) {
				if (wake_up[i]) {
					//printf ("[%d] Waking up %c\n", year, i + 'A');
					wake_up[i] = 0;
					is_awake[i] = 1;
					n_asleep--;

					for (int j = 0; j < 26; j++)
						if (has_edge[i][j])
							ct_awake_conn[j][i] = 1;
				}
			}

			year++;
		}

		if (n_asleep == 0)
			printf ("WAKE UP IN, %d, YEARS\n", year);
		else
			printf ("THIS BRAIN NEVER WAKES UP\n");
	}

	return 0;
}
