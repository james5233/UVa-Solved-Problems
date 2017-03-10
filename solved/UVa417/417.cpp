#include <bits/stdc++.h>
using namespace std;

inline unsigned hsh (char s[], int len)
{
	unsigned res = 0;
	for (int i = 0; i < len; i++) {
		res <<= 5;
		res += (s[i] - 'a' + 1);
	}

	return res;
}

int main ()
{
	map<int, int> mp;
	int rank = 0;

	for (int l = 1; l <= 5; l++) {
		char str[l + 1];
		for (int i = 0; i < l; i++)
			str[i] = 'a' + i;
		str[l] = '\0';

		while (true) {
			unsigned res = hsh (str, l);
			mp[res] = ++rank;
			//printf ("%s\n", str);
			
			int i = l - 1;
			while (i >= 0) {
				if (str[i] == ('z' - ((l - 1) - i))) {
					i--;
				} else { 
					str[i]++;
					break;
				}
			}

			if (i < 0) {
				break;
			} else {
				int sav = i++;
				int j = 1;
				while (i <= l - 1)
					str[i++] = str[sav] + j++;
			}
		}
	}
	
	char s[10];
	int st, end;
	while (scanf (" %n%s%n", &st, s, &end) == 1) {
		int l = end - st;
		int i;
		
		for (i = 1; i < l; i++)
			if (s[i] <= s[i - 1])
				break;

		if (i >= l) {
			unsigned int h = hsh (s, l);
			printf ("%u\n", mp[h]);
		} else {
			printf ("0\n");
		}
	}

	return 0;
}




