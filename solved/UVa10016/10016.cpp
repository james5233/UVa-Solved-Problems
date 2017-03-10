#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define XOR_SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)
#define PRN_ARR(arr, N) do {\
		for (int i = 0; i < N; i++) {\
			for (int j = 0; j < N - 1; j++)\
				printf ("%d ", arr[i][j]);\
			printf ("%d\n", arr[i][N-1]);\
		}\
	} while (0)

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N;
		scanf ("%d", &N);

		int arr[N][N];
		int n_rings = (N + 1)/2;

		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				scanf ("%d ", &(arr[i][j]));
		
		D( printf ("DEBUG: Array read:\n"); 
			PRN_ARR (arr, N); )

		for (int r = 0; r < n_rings; r++) {
			int M;
			int rs = r, re = N - 1 - r;
			int cs = rs, ce = re;

			for (scanf ("%d", &M); M--;) {
				int action;
				scanf ("%d", &action);
				
				if (rs == re)
					continue;

				if (action == 1) {
					int st, end;
					for (st = rs, end = re; st < end; st++, end--) {
						XOR_SWAP (arr[st][cs], arr[end][cs]);
						XOR_SWAP (arr[st][ce], arr[end][ce]);
					}

					for (int j = cs + 1; j < ce; j++) { 
						XOR_SWAP (arr[rs][j], arr[re][j]);
					}
					
					D( printf ("DEBUG: Array after Upside-down flip:\n"); 
							PRN_ARR (arr, N); )
					
				} else if (action == 2) {
					int st, end;
					for (st = cs, end = ce; st < end; st++, end--) {
						XOR_SWAP (arr[rs][st], arr[rs][end]);
						XOR_SWAP (arr[re][st], arr[re][end]);
					}

					for (int i = rs + 1; i < re; i++) { 
						XOR_SWAP (arr[i][cs], arr[i][ce]);
					}
					
					D( printf ("DEBUG: Array after Left-Right flip:\n"); 
							PRN_ARR (arr, N); )
					
				} else if (action == 3) {
					int D = ce - cs;

					for (int d = 1; d < D; d++) {
						XOR_SWAP (arr[rs + d][cs], arr[rs][cs + d]);
						XOR_SWAP (arr[re - d][ce], arr[re][ce - d]);
					}

					XOR_SWAP (arr[re][cs], arr[rs][ce]);
					
					D( printf ("DEBUG: Array after Main-Diagonal flip:\n"); 
							PRN_ARR (arr, N); )
				} else if (action == 4) {
					int D = ce - cs;

					for (int d = 1; d < D; d++) {
						XOR_SWAP (arr[rs][ce - d], arr[rs + d][ce]);
						XOR_SWAP (arr[re - d][cs], arr[re][cs + d]);
					}

					XOR_SWAP (arr[rs][cs], arr[re][ce]);
					D( printf ("DEBUG: Array after Inverse-Diagonal flip:\n"); 
							PRN_ARR (arr, N); )
				}
			}
		}
		
		D( printf ("DEBUG: Final:\n"); )
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - 1; j++)
				printf ("%d ", arr[i][j]);
			printf ("%d\n", arr[i][N-1]);
		}
	}

	return 0;
}

					



