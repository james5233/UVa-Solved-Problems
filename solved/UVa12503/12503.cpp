#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

int main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N, instr[MAXN];
		char cmd[20];
		int pos = 0;

		scanf ("%d", &N);
		for (int n = 1; n <= N; n++) {
			scanf (" %s", cmd);
			if (!strcmp (cmd, "LEFT"))
				instr[n] = -1;
			else if (!strcmp (cmd, "RIGHT"))
				instr[n] = 1;
			else {
				int i;
				scanf (" %*s%d", &i);
				instr[n] = instr[i];
			}

			pos += instr[n];
		}

		printf ("%d\n", pos);
	}

	return 0;
}
