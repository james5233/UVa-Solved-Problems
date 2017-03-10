#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

typedef unsigned long ul;
typedef vector<ul> vul;
typedef priority_queue<ul> max_pq;
typedef priority_queue<ul, vul, greater<ul> > min_pq;

int
main ()
{
	max_pq left;
	min_pq right;

	unsigned long n;
	int l, r;
	
	left.push (0UL);
	right.push (ULONG_MAX);

	l = r = 1;
	long ct = 2;
	while (scanf ("%lu", &n) != EOF) {
		unsigned long lo, hi;
		ct++;

		lo = left.top ();
		hi = right.top ();
		D( printf ("DEBUG: Going to insert %lu\n", n); )
		D( printf ("DEBUG: lo = %lu, hi = %lu, [%d : %d]\n", lo, hi, l, r); )

		if (n < lo) {
			if (l <= r) {
				left.push (n);
				D( printf ("\tDEBUG: Inserted into left.\n"); )
				l++;
			} else {
				left.pop ();
				left.push (n);
				D( printf ("\tDEBUG: Inserted into left after lo --> right.\n"); )

				right.push (lo);
				r++;
			}
		} else if (n >= lo && n <= hi) {
			if (l <= r) {
				left.push (n);
				D( printf ("\tDEBUG: Inserted into left.\n"); )
				l++;
			} else {
				right.push (n);
				D( printf ("\tDEBUG: Inserted into right.\n"); )
				r++;
			}
		} else {
			if (l <= r) {
				right.pop ();
				right.push (n);
				D( printf ("\tDEBUG: Inserted into right after left <-- hi.\n"); )

				left.push (hi);
				l++;
			} else {
				right.push (n);
				D( printf ("\tDEBUG: Inserted into right.\n"); )
				r++;
			}
		}

		if (ct % 2)
			printf ("%lu\n", left.top ());
		else {
			unsigned long lo = left.top ();
			unsigned long hi = right.top ();

			printf ("%lu\n", lo + (hi - lo)/2UL);
		}
	}

	return 0;
}
