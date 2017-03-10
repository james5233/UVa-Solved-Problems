#include <bits/stdc++.h>
using namespace std;

long M;

bool cmp_long (long a, long b)
{
	long m_a, m_b;
	m_a = a % M;
	m_b = b % M;

	if (m_a < m_b)
		return true;
	else if (m_a == m_b) {
		bool a_is_odd = !(a % 2 == 0);
		bool b_is_odd = !(b % 2 == 0);

		if (a_is_odd && b_is_odd)
			return (a > b);
		else if (!a_is_odd && !b_is_odd)
			return (a < b);
		else
			return a_is_odd;
	} else
		return false;
}

int
main ()
{
	long N;

	while (scanf ("%ld %ld", &N, &M), N || M) {
		vector<long> v;
		for (long n = 0; n < N; n++) {
			long num;
			scanf ("%ld", &num);
			v.push_back (num);
		}

		sort (v.begin (), v.end (), cmp_long);

		vector<long>::iterator it;
		
		printf ("%ld %ld\n", N, M);
		for (it = v.begin (); it != v.end (); it++)
			printf ("%ld\n", *it);
	}
	
	printf ("0 0\n");
	return 0;
}

