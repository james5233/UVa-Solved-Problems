#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 300

int
main ()
{
	char line[MAXLLEN], word[MAXLLEN];
	set<string> s;
	string cont = "";
	
	while (fgets (line, MAXLLEN, stdin)) {
		char *p;
		int len;
		
		p = line;
		len = 0;
		sscanf (p, "%*[^a-zA-Z]%n", &len);
		if (len) {
			if (cont.size ())
				s.insert (cont);
			cont = "";
		}
		p += len;

		while (!(len = 0) && sscanf (p, "%[a-zA-Z]%n", word, &len) == 1) {
			
			for (char *str = word; *str; str++)
				*str = tolower (*str);
			
			cont += word;

			if (p[len] != '-') {
				s.insert (cont);
				cont = "";
			}
			
			p += len;
			len = 0;
			sscanf (p, "%*[^a-zA-Z]%n", &len);
			if (cont.size ()) {
				if (len == 1)
					cont += "-";
				else if (len > 2) {
					s.insert (cont);
					cont = "";
				}
			}

			p += len;
		}
	}

	set<string>::iterator it;
	for (it = s.begin (); it != s.end (); it++)
		puts (it->c_str ());
  
	return 0;
}
			

