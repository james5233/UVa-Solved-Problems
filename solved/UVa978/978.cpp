#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int B, SG, SB;
		int num;

		scanf ("%d %d %d", &B, &SG, &SB);
		
		vector<int> Green (B), Blue (B);
		priority_queue<int> army_Green, army_Blue;
		
		for (int i = 0; i < SG; i++) {
			scanf ("%d", &num);
			army_Green.push (num);
		}

		for (int i = 0; i < SB; i++) {
			scanf ("%d", &num);
			army_Blue.push (num);
		}
		
		int sz_Green, sz_Blue;
		while ((sz_Green = army_Green.size ()) && 
			(sz_Blue = army_Blue.size ())) {
			int sz = min (sz_Green, sz_Blue);
			sz = min (sz, B);
			for (int i = 0; i < sz; i++) {
				int g, b;
				g = army_Green.top ();
				army_Green.pop ();

				b = army_Blue.top ();
				army_Blue.pop ();
				
				Green[i] = g - b;
				Blue[i] = b - g;
			}

			for (int i = 0; i < sz; i++) {
				if (Green[i] > 0)
					army_Green.push (Green[i]);

				if (Blue[i] > 0)
					army_Blue.push (Blue[i]);
			}
		}

		sz_Green = army_Green.size ();
		sz_Blue = army_Blue.size ();

		if (sz_Green == 0) {
			if (sz_Blue == 0)
				printf ("green and blue died\n");
			else {
				printf ("blue wins\n");
				while (army_Blue.size ()) {
					printf ("%d\n", army_Blue.top ());
					army_Blue.pop ();
				}
			}
		} else {
			printf ("green wins\n");
			while (army_Green.size ()) {
				printf ("%d\n", army_Green.top ());
				army_Green.pop ();
			}
		}

		if (T)
			printf ("\n");
	}

	return 0;
}

				

