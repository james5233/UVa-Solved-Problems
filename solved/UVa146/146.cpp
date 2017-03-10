#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define MAXSTR 200
#define XOR_SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)

int
main ()
{
	char s[MAXSTR];
	int st, end;

	while (scanf (" %n%s%n", &st, s, &end), (*s != '#')) {
		int l = end - st;
		int i, j;
		
		D( printf ("DEBUG: [%s %d]\n", s, l);)

		bool found = false;
		for (i = l - 2; i >= 0; i--)
			if (s[i] < s[i+1]) {
				found = true;
				break;
			}

		D( printf ("DEBUG: i: s[%d] = %c\n", i, s[i]);)

		if (!found) {
			printf ("No Successor\n");
			continue;
		}

		for (j = l - 1; j > i && s[j] <= s[i]; j--);
		
		D( printf ("DEBUG: j: s[%d] = %c\n", j, s[j]);)

		XOR_SWAP (s[i], s[j]);
		sort (s + i + 1, s + l);
		printf ("%s\n", s);
	}

	return 0;
}
