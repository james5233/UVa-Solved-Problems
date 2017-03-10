#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N, M;
	scanf ("%d %d ", &N, &M);
	
	unordered_map<string, long> val;
	//printf ("N = %d, M = %d\n", N, M);
	
	for (int n = 0; n < N; n++) {
		char line[200], word[200];
		long num;
		fgets (line, 200, stdin);
		//puts (line);

		sscanf (line, "%s %ld", word, &num);
		val[word] = num;
	}
	
	long salary = 0;
	for (int m = 0; m < M;) {
		char line[20000];

		fgets(line, 20000, stdin);
		//puts (line);
		if (*line == '.') {
			printf ("%ld\n", salary);
			salary = 0;
			m++;
		} else {
			char *p = line;
			char word[2000];
			int l;

			while (sscanf (p, "%s%n", word, &l) == 1) {
				//puts (word);
				unordered_map<string, long>::iterator it = val.find (word);
				if (it != val.end ())
					salary += it->second;

				p += l;
			}
		}
	}

	return 0;
}
