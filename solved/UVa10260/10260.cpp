#include <bits/stdc++.h>
using namespace std;

int main ()
{
	char s[100];

	s['B'] = s['F'] = s['P'] = s['V'] = 1;
	s['C'] = s['G'] = s['J'] = s['K'] = 
	s['Q'] = s['S'] = s['X'] = s['Z'] = 2;
	s['D'] = s['T'] = 3;
	s['L'] = 4;
	s['M'] = s['N'] = 5;
	s['R'] = 6;
	s['A'] = s['E'] = s['I'] = s['O'] = s['U'] = s['H'] = s['W'] = s['Y'] = 0;
	
	char word[50];

	while (scanf (" %s", word) != EOF) {
		int old = s[word[0]];
		char snd[50];
		int p = 0;

		if (old != 0)
			snd[p++] = old + '0';

		for (int i = 1; word[i] != '\0'; i++) {
			int cur = s[word[i]];

			if (cur != 0 && cur != old)
				snd[p++] = cur + '0';

			old = cur;
		}

		snd[p] = '\0';
		printf ("%s\n", snd);
	}

	return 0;
}
