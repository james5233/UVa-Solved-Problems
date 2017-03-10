#include <bits/stdc++.h>
using namespace std;

#define MAXSTR 2000

void 
bk_trace (char *s, char *e, char *stk, char *p, int i, int o, int N) 
{
	if (o == N) {
		int lim = 2 * N;
		for (int j = 0; j < lim - 1; j++)
			printf ("%c ", p[j]);
		printf ("%c\n", p[lim - 1]);
	} else {
		if (i < N) {
			p[i + o] = 'i';
			char sav = stk[i - o];
			stk[i - o] = s[i];
			bk_trace (s, e, stk, p, i + 1, o, N);
			stk[i - o] = sav;
		}

		if (i > o && stk[i - o - 1] == e[o]) {
			p[i + o] = 'o';
			bk_trace (s, e, stk, p, i, o + 1, N);
		}
	}
}

int
main ()
{
	char s[MAXSTR], e[MAXSTR], stk[2 * MAXSTR], p[2 * MAXSTR];
	int s_st, s_end, e_st, e_end;

	while (scanf (" %n%s%n %n%s%n", &s_st, s, &s_end, 
  &e_st, e, &e_end) != EOF) {
		int s_len, e_len;
		s_len = s_end - s_st;
		e_len = e_end - e_st;

		printf ("[\n");
		if (s_len == e_len)
			bk_trace (s, e, stk, p, 0, 0, s_len);
		printf ("]\n");
	}

	return 0;
}
