#include <bits/stdc++.h>
using namespace std;

#define SET_BIT(x, n) ((x) |= (1U << (n)))
#define IS_SET(x, n) (((x) & (1U << (n))) != 0)

int
main ()
{
	unsigned int N;
	while (scanf ("%u", &N), N) {
		unsigned int n;
		vector<unsigned int> v;

		for (n = 0; n < 32U; n++) {
			if (IS_SET(N, n))
				v.push_back (n);
		}

		unsigned int a, b;
		a = b = 0;

		unsigned int sz = v.size ();

		for (n = 0; n < sz; n += 2)
			SET_BIT (a, v[n]);

		for (n = 1; n < sz; n += 2)
			SET_BIT (b, v[n]);

		printf ("%u %u\n", a, b);
	}

	return 0;
}
