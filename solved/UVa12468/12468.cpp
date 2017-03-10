#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b;

	while (scanf ("%d%d", &a, &b), (a != -1 && b != -1)) {
		int diff = max (a, b) - min (a, b);
		if (diff > 50)
			diff = 100 - diff;

		printf ("%d\n", diff);
	}

	return 0;
}
