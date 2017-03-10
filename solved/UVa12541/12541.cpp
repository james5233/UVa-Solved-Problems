#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	char name[50];
	int d, m, y;

	long min_dt, max_dt;
	char min_nm[50], max_nm[50];

	scanf ("%d", &N);

	scanf (" %s %d %d %d", name, &d, &m, &y);
	min_dt = max_dt = (y * 10000L + m * 100L + d);
	strcpy (min_nm, name);
	strcpy (max_nm, name);

	for (int i = 1; i < N; i++) {
		long dt;
		scanf (" %s %d %d %d", name, &d, &m, &y);
		dt = (y * 10000L + m * 100L + d);
		
		if (dt < min_dt) {
			min_dt = dt;
			strcpy (min_nm, name);
		} else if (dt > max_dt) {
			max_dt = dt;
			strcpy (max_nm, name);
		}
	}

	printf ("%s\n%s\n", max_nm, min_nm);
	return 0;
}

