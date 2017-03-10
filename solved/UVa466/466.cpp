#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define MAXN 12

void disp (int arr[MAXN][MAXN], int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf ("%d ", arr[i][j]);
		printf ("\n");
	}
}


void rot90 (int arr[MAXN][MAXN], int N) 
{
	int rs, re;

	for (rs = 0, re = N - 1; rs < re; rs++, re--) {
		int cs, ce, D;
		
		cs = rs;
		ce = re;
		D = ce - cs;

		for (int d = 0; d < D; d++) {
			int sav = arr[rs + d][cs];
			arr[rs + d][cs] = arr[re][cs + d];
			arr[re][cs + d] = arr[re - d][ce];
			arr[re - d][ce] = arr[rs][ce - d];
			arr[rs][ce - d] = sav;
		}
	}
}

bool is_equal (int a[MAXN][MAXN], int b[MAXN][MAXN], int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (a[i][j] != b[i][j])
				return false;
	
	return true;
}

void flip_vert (int arr[MAXN][MAXN], int N)
{
	int rs, re;

	for (rs = 0, re = N - 1; rs < re; rs++, re--) {
		for (int c = 0; c < N; c++) {
			int sav = arr[rs][c];
			arr[rs][c] = arr[re][c];
			arr[re][c] = sav;
		}
	}
}

int
main ()
{
	int N;
	int case_no = 0;

	while (scanf ("%d", &N) != EOF) {
		int s[MAXN][MAXN], f[MAXN][MAXN];

		char str_s[20], str_f[20];
		for (int i = 0;i < N; i++) {
			scanf (" %s %s", str_s, str_f);
			for (int j = 0; j < N; j++) {
				s[i][j] = (str_s[j] == 'X');
				f[i][j] = (str_f[j] == 'X');
			}
		}
		
		D( printf ("s = \n");
		disp (s, N);
		
		printf ("f = \n");
		disp (f, N); )

		++case_no;

		if (is_equal (s, f, N))
			printf ("Pattern %d was preserved.\n", case_no);
		else {
			int ang = 90;
			while (ang < 360) {
				rot90 (s, N);
				D( printf ("rotated by %d deg\n", ang);
				disp (s, N); )
				if (is_equal (s, f, N)) {
					printf ("Pattern %d was rotated %d degrees.\n", case_no, ang);
					break;
				}

				ang += 90;
			}

			if (ang == 360) {
				rot90 (s, N);
				flip_vert (s, N);
				
				if (is_equal (s, f, N))
					printf ("Pattern %d was reflected vertically.\n", case_no);
				else {
					int ang = 90;
					while (ang < 360) {
						rot90 (s, N);
						if (is_equal (s, f, N)) {
							printf ("Pattern %d was reflected vertically and " 
							"rotated %d degrees.\n", case_no, ang);
							break;
						}

						ang += 90;
					}

					if (ang == 360)
						printf ("Pattern %d was improperly transformed.\n", case_no);
				}
			}
		}
	}

	return 0;
}
