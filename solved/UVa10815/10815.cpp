#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 300

int
main ()
{
	char line[MAXLLEN], word[MAXLLEN];
	set<string> s;

	while (fgets (line, MAXLLEN, stdin)) {
		char *p;
		int len;
		
		p = line;
		len = 0;
		sscanf (p, "%*[^a-zA-Z]%n", &len);
		p += len;

		while (!(len = 0) && sscanf (p, "%[a-zA-Z]%n", word, &len) == 1) {
			
			for (char *str = word; *str; str++)
				*str = tolower (*str);

			s.insert (word);
			
			p += len;
			len = 0;
			sscanf (p, "%*[^a-zA-Z]%n", &len);
			p += len;
		}
	}

	set<string>::iterator it;
	for (it = s.begin (); it != s.end (); it++)
		puts (it->c_str ());
  
	return 0;
}
			

