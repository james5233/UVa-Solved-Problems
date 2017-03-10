#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef queue<pii> qpii;

#define MAXN 12
#define MAXSZ 36

#define FILL_2D(arr, R, C, val) do {\
	for (int _i = 0; _i < R; _i++)\
		for (int _j = 0; _j < C; _j++)\
			arr[_i][_j] = val;\
	} while (0)

#define COPY_2D(dest, src, R, C) do {\
	for (int _i = 0; _i < R; _i++)\
		for (int _j = 0; _j < C; _j++)\
			dest[_i][_j] = src[_i][_j];\
	} while (0)

#define FIRST_HIT_2D(arr, R, C, val, r_i, r_j) do {\
	r_i = r_j = -1;\
	bool _found = false;\
	for (int _i = 0; _i < R && !_found; _i++)\
		for (int _j = 0; _j < C; _j++)\
			if (arr[_i][_j] == val) {\
				r_i = _i;\
				r_j = _j;\
				_found = true;\
				break;\
			}\
	} while (0)

int
main ()
{
	int N, M;
	int store[3][MAXSZ][MAXSZ];
	int (*s)[MAXN], (*f)[MAXN], (*g)[MAXN];

	s = (int (*)[MAXN])(&(store[0][MAXN][MAXN]));
	f = (int (*)[MAXN])(&(store[1][MAXN][MAXN]));
	g = (int (*)[MAXN])(&(store[2][MAXN][MAXN]));

	while (scanf ("%d%d", &N, &M), N || M) {
		
		FILL_2D (store[0], MAXSZ, MAXSZ, 0);
		FILL_2D (store[1], MAXSZ, MAXSZ, 0);
		
		for (int i = 0; i < N; i++) {
			char str[20];
			scanf (" %s", str);
			
			for (int j = 0; j < N && str[j] != '\0'; j++)
				f[i][j] = (str[j] == '*');
		}

		for (int i = 0; i < M; i++) {
			char str[20];
			scanf (" %s", str);

			for (int j = 0; j < M && str[j] != '\0'; j++)
				s[i][j] = (str[j] == '*');
		}

		COPY_2D (store[2], store[1], MAXSZ, MAXSZ);

		int s_i, s_j, f_i, f_j;
		bool valid = true;

		for (int k = 0; k < 2 && valid; k++) {
			FIRST_HIT_2D (f, MAXN, MAXN, 1, f_i, f_j);
			FIRST_HIT_2D (s, MAXN, MAXN, 1, s_i, s_j);

			if (s_i < 0 || f_i < 0) {
				valid = false;
				continue;
			}
			
			int d_i, d_j;

			d_i = f_i - s_i;
			d_j = f_j - s_j;

			bool valid = true;
			for (int i = s_i; i < M && valid; i++) {
				for (int j = 0; j < M && valid; j++) {
					f[i + d_i][j + d_j] -= s[i][j];
					if (f[i + d_i][j + d_j] < 0)
						valid = false;
				}
			}
		}

		for (int i = 0; i < N && valid; i++)
			for (int j = 0; j < N && valid; j++)
				if (f[i][j])
					valid = false;

		if (valid) {
			int i, j;
			FIRST_HIT_2D (g, MAXN, MAXN, 1, i, j);
			qpii q;

			q.push (make_pair (i, j));
			while (!q.empty ()) {
				pii t = q.front ();
				q.pop ();

				i = t.first; j = t.second;
				g[i][j] = 0;

				if (g[i-1][j]) q.push (make_pair (i-1, j));
				if (g[i+1][j]) q.push (make_pair (i+1, j));
				if (g[i][j-1]) q.push (make_pair (i, j-1));
				if (g[i][j+1]) q.push (make_pair (i, j+1));
			}

			FIRST_HIT_2D (g, MAXN, MAXN, 1, i, j);

			if (i >= 0)
				printf ("0\n");
			else
				printf ("1\n");
		} else
			printf ("0\n");
	}

	return 0;
}



