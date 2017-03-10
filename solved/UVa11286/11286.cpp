#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N;
	while (scanf ("%d ", &N), N) {
		unordered_map<string, int> ct;
		int M = 0;

		for (int i = 0; i < N; i++) {
			int arr[5];
			char str[30];
			scanf ("%d %d %d %d %d", arr, arr+1, arr+2, arr+3, arr+4);
			sort (arr, arr + 5);
			sprintf (str, "%d%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4]);
			
			string s = str;
			int mx = ++(ct[s]);
			M = max (M, mx);
		}
		
		unordered_map<string, int>::iterator it;
		int count  = 0;
		for (it = ct.begin (); it != ct.end (); it++)
			if (it->second == M)
				count += M;

		printf ("%d\n", count);
	}

	return 0;
}

