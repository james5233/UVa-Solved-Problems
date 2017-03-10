#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;


#define XOR_SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)
#define MAXSTR 2000

int
main ()
{
	int N, n;

	while (scanf ("%d%d ", &N, &n), N || n) {
		vvc str (N), pat (n);

		for (int i = 0; i < N; i++) {
			char s[MAXSTR];
			scanf (" %s", s);
			str[i].insert (str[i].end (), s, s + N);
		}

		for (int i = 0; i < n; i++) {
			char s[MAXSTR];
			scanf (" %s", s);
			pat[i].insert (pat[i].end (), s, s + n);
		}
		
		int ct[4];

		for (int i = 0; i < 4; i++) {
			ct[i] = 0;

			for (int x = 0; x <= N - n; x++) {
				for (int y = 0; y <= N - n; y++) {
					for (int p = 0; p < n; p++)
						for (int q = 0; q < n; q++)
							if (str[x + p][y + q] != pat[p][q])
								goto over;

					ct[i]++;
					over: ;
				}
			}
			
			int rs, re;
			for (rs = 0, re = n - 1; rs < re; rs++, re--) {
				int D = re - rs;
				int cs, ce;

				cs = rs; ce = re;
				for (int d = 0; d < D; d++) {
					char sav = pat[rs + d][cs];
					pat[rs + d][cs] = pat[re][cs + d];
					pat[re][cs + d] = pat[re - d][ce];
					pat[re - d][ce] = pat[rs][ce -d];
					pat[rs][ce - d] = sav;
				}
			}
		}

		printf ("%d %d %d %d\n", ct[0], ct[1], ct[2], ct[3]);
	}

	return 0;
}

