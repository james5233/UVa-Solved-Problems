#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<int, int> umapi_t;

int
main ()
{
	int n_courses, n_categories;
	while (scanf ("%d%d", &n_courses, &n_categories), n_courses) {
		umapi_t course;
		bool pass = true;

		for (int i = 0; i < n_courses; i++) {
			int c;
			scanf ("%d", &c);
			course[c] = i;
		}

		for (int i = 0; i < n_categories; i++) {
			int ct, minx;
			scanf ("%d%d", &ct, &minx);

			int x = 0;
			for (int j = 0; j < ct; j++) {
				int c;
				scanf ("%d", &c);
				if (course.find (c) != course.end ())
					x++;
			}

			if (x < minx)
				pass = false;
		}

		if (pass)
			printf ("yes\n");
		else
			printf ("no\n");
	}

	return 0;
}
