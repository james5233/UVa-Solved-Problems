#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	char mp[256];
	mp['A'] = mp['B'] = mp['C'] = 2;
	mp['D'] = mp['E'] = mp['F'] = 3;
	mp['G'] = mp['H'] = mp['I'] = 4;
	mp['J'] = mp['K'] = mp['L'] = 5;
	mp['M'] = mp['N'] = mp['O'] = 6;
	mp['P'] = mp['R'] = mp['S'] = 7;
	mp['T'] = mp['U'] = mp['V'] = 8;
	mp['W'] = mp['X'] = mp['Y'] = 9;
	
	int T;
	bool first = true;
	for (scanf ("%d ", &T); T--;) {
		int N;
		scanf ("%d ", &N);
		
		vector<int> v;
		for (int n = 0; n < N; n++) {
			char str[50];
			scanf ("%s ", str);
			
			int num = 0;
			for (char *p = str; *p != '\0'; p++) {
				if (*p >= '0' && *p <= '9')
					num = num * 10 + (*p - '0');
				else if (*p >= 'A' && *p <= 'Z')
					num = num * 10 + mp[*p];
			}

			v.push_back (num);
		}

		sort (v.begin (), v.end ());
		int old_num = v[0];
		int ct = 0;
		bool no_duplicates = true;
		
		if (first)
			first = false;
		else
			printf ("\n");
			
		for (int n = 0; n < N; n++) {
			int num = v[n];
			if (num == old_num)
				ct++;
			else if (ct > 1) {
				char std_form[10];
				sprintf (std_form, "%07d", old_num);
				printf ("%.3s-%.4s %d\n", std_form, std_form + 3, ct);
				ct = 1;
				no_duplicates = false;
			}

			old_num = num;
		}

		if (ct > 1) {
			char std_form[10];
			sprintf (std_form, "%07d", old_num);
			printf ("%.3s-%.4s %d\n", std_form, std_form + 3, ct);
			ct = 1;
			no_duplicates = false;
		}

		if (no_duplicates)
			printf ("No duplicates.\n");

	}

	return 0;
}



