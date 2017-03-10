#include <bits/stdc++.h>
using namespace std;

#define MAXSTR 100009

int
main ()
{
	char str[MAXSTR];

	while (scanf ("%[^\n]", str) != EOF) {
		getchar ();

		list<char> l;
		list<char>::iterator it;

		it = l.begin ();
			
		char c;
		for (int i = 0; (c = str[i]) != '\0'; i++) {
			if (c == '[') 
				it = l.begin ();
			else if (c == ']') 
				it = l.end ();
			else
				l.insert (it, c);
		}

		int i = 0;
		for (it = l.begin (); it != l.end (); it++) 
			str[i++] = *it;
		
		str[i] = '\0';

		printf ("%s\n", str);
	}

	return 0;
}


