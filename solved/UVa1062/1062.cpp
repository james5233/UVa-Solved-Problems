#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

int
main ()
{
	string inp;
	int case_no = 0;

	while (cin >> inp && inp != "end") {
		vector<char> v;
		int len = inp.length ();
		
		D( printf ("DEBUG: String is [%s %d]\n", inp.c_str (), len); )
		
		for (int i = 0; i < len; i++) {
			int l = v.size ();
			int min_j = -1;
			char min_c = 'Z' + 1;

			D( printf ("DEBUG: Trying to insert %c:\n", inp[i]); )
			for (int j = 0; j < l; j++) {
				if (v[j] >= inp[i] && v[j] < min_c) {
					min_c = v[j];
					min_j = j;
				}
			}

			if (min_j >= 0) {
				D( printf ("\tFound at pos %d: %c\n", min_j, min_c); )
				v[min_j] = inp[i];
			} else {
				v.push_back (inp[i]);
				D( printf ("\tNot Found: Inserting: v.size () = %d\n", 
				(int)(v.size ())); )
			}
		}

		printf ("Case %d: %d\n", ++case_no, (int)(v.size ()));
	}

	return 0;
}

