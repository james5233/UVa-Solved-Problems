#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define MAXSTR 500
#define FILL_2D(arr, R, C, val) do {\
	for (int _i = 0; _i < R; _i++)\
		for (int _j = 0; _j < C; _j++)\
			arr[_i][_j] = val;\
	} while (0)

int
main ()
{
	char str[MAXSTR];
	int arr[5][5];
	int case_no = 0;
	int st, end;
	int status;
		
	while ((status = scanf ("%n%[^\n]%n", &st, str, &end)) != EOF) {
		int l = end - st;
		
		if (status != 1)
			l = 0;
	
		getchar ();
		
		D( printf ("DEBUG: l = %d\n", l); )

		FILL_2D (arr, 5, 5, 0);
		while (l > 0) {
			char ch = str[--l];
			int i, j;

			D( printf ("DEBUG: Character is [%c]\n", ch); )
			
			i = (ch - 'a') / 3 + 1;
			j = (ch - 'a') % 3 + 1;

			arr[i][j] = (arr[i][j] + 1) % 10;
			arr[i-1][j] = (arr[i-1][j] + 1) % 10;
			arr[i+1][j] = (arr[i+1][j] + 1) % 10;
			arr[i][j-1] = (arr[i][j-1] + 1) % 10;
			arr[i][j+1] = (arr[i][j+1] + 1) % 10;
		}

		printf ("Case #%d:\n", ++case_no);
		for (int i = 1; i <= 3; i++)
			printf ("%d %d %d\n", arr[i][1], arr[i][2], arr[i][3]);

	}

	return 0;
}



		
