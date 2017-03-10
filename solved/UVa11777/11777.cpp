#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	double weight[] = {20, 20, 30, 10, 20};
	
	int T;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t++) {
		int class_test[3];
		double marks[5];

		for (int i = 0; i < 4; i++) {
			int num;
			scanf ("%d", &num);
			marks[i] = num;
		}
		
		for (int i = 0; i < 3; i++)
			scanf ("%d", class_test + i);

		int ct_tot = accumulate (class_test + 0, class_test + 3, 0);
		ct_tot -= *(min_element (class_test + 0, class_test + 3));
		marks[4] = ct_tot / 2.0;
   
	  double total = accumulate (marks + 0, marks + 5, 0.0);
		
		if (total >= 90.0)
			printf ("Case %d: %c\n", t, 'A');
		else if (total >= 80.0)
			printf ("Case %d: %c\n", t, 'B');
		else if (total >= 70.0)
			printf ("Case %d: %c\n", t, 'C');
		else if (total >= 60.0)
			printf ("Case %d: %c\n", t, 'D');
		else
			printf ("Case %d: %c\n", t, 'F');
	}

	return 0;
}
