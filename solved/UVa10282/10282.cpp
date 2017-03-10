#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, string> mp;
	char str[200];
	
	while (scanf ("%[^\n]", str) == 1) {
		getchar ();
		char *p;
		for (p = str; *p != ' '; p++);
		*(p++) = '\0';
		mp[p] = str;
	}
	
	getchar ();
	while (scanf ("%[^\n]", str) == 1) {
		getchar ();
		map<string, string>::iterator it = mp.find (str);
		if (it == mp.end ())
			printf ("eh\n");
		else
			printf ("%s\n", it->second.c_str ());
	}

	return 0;
}
