#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define MAXN 12
#define XOR_SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)
		
#define PRN_ARR(arr, N) do {\
		for (int i = 0; i < N; i++)\
			printf ("%s\n", arr[i]);\
		} while (0)


int
main ()
{
	int T;
	scanf ("%d", &T);

	char arr[MAXN][MAXN];

	for (int t = 1; t <= T; t++) {
		int N;
		scanf (" %d", &N);
		
		for (int i = 0; i < N; i++)
			scanf (" %s", arr[i]);

		int inc;
		inc = 0;

		D( printf ("DEBUG: Array read.\n");
			PRN_ARR (arr, N); )
		
		int M;
		for (scanf (" %d", &M); M--;) {
			char cmd[30];
			scanf (" %s", cmd);
			D( printf ("DEBUG: Command is [%s]\n", cmd); )

			if (!strcmp (cmd, "inc"))
				inc = (inc + 1) % 10;
			else if (!strcmp (cmd, "dec"))
				inc = (inc - 1 + 10) % 10; 
			else if (!strcmp (cmd, "row")) {
				int a, b;
				scanf ("%d%d", &a, &b);
				a--;
				b--;

				for (int j = 0; j < N; j++)
					XOR_SWAP (arr[a][j], arr[b][j]);

				D( printf ("DEBUG: Row Exchange %d <--> %d\n", a, b);
					PRN_ARR (arr, N);)
			} else if (!strcmp (cmd, "col")) {
				int a, b;
				scanf ("%d%d", &a, &b);
				a--;
				b--;

				for (int i = 0; i < N; i++)
					XOR_SWAP (arr[i][a], arr[i][b]);
				
				D( printf ("DEBUG: Column Exchange %d <--> %d\n", a, b);
					PRN_ARR (arr, N);)
			} else if (!strcmp (cmd, "transpose")) {
				
				for (int i = 0; i < N; i++)
					for (int j = 1; j < N - i; j++)
						XOR_SWAP (arr[i + j][i], arr[i][i + j]);
				
				D( printf ("DEBUG: Transpose\n");
					PRN_ARR (arr, N);)
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				arr[i][j] = (arr[i][j] - '0' + inc) % 10 + '0';
		
		D( printf ("DEBUG: Final\n"); )
		printf ("Case #%d\n", t);
		for (int i = 0; i < N; i++)
			printf ("%s\n", arr[i]);
		printf ("\n");

	}
	
	return 0;
}
