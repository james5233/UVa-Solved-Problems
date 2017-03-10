#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define MAXLLEN 200
int
main ()
{
	int T;
	char line[MAXLLEN];

	for (scanf ("%d ", &T); T--;) {
		int N;
		unordered_map<string, int> store;
		unordered_map<string, vector<int> > ind;

		vector<string> cat_names;
		vector<int> req_hits, act_hits;

		fgets (line, MAXLLEN, stdin);
		sscanf (line, "%d", &N);
		
		D( printf ("[%d]\n", N); )
		for (int n = 0; n < N; n++) {
			char category[MAXLLEN];
			int M, req;
			fgets (line, MAXLLEN, stdin);
			sscanf (line, "%s %d %d", category, &M, &req);
			D( printf ("Category: [%s] [%d|%d]\n", category, M, req); )
			cat_names.push_back (category);
			req_hits.push_back (req);
			act_hits.push_back (0);

			store.clear ();

			for (int m = 0; m < M; m++) {
				char keyword[MAXLLEN];
				fgets (line, MAXLLEN, stdin);
				sscanf (line, "%s", keyword);
				
				unordered_map<string, int>::iterator it = store.find (keyword);
				if (it == store.end ()) {
					store[keyword] = 1;
					D( printf ("\tkeyword [%s]\n", keyword); )
					ind[keyword].push_back (n);
				}
			}
		}
		
		store.clear ();
		while (fgets (line, MAXLLEN, stdin) && (*line != '\n')) {
			char *p = line;
			int len;
			char word[MAXLLEN];
			
			len = 0;
			sscanf (p, "%*[^a-zA-Z]%n", &len);
			p += len;
			len = 0;
			
			while (sscanf (p, "%[a-zA-Z]%n", word, &len) == 1) {
				
				D( printf ("word [%s]\n", word); )
				if (store.find (word) == store.end ()) {
					store[word] = 1;
					D( printf ("New word [%s]\n", word); )
					
					unordered_map<string, vector<int> >::iterator it;
					
					if ( (it = ind.find (word)) != ind.end ()) {
						vector<int>::iterator iter;
						for (iter = it->second.begin (); 
						iter != it->second.end (); iter++)
							act_hits[*iter]++;
					}
				}

				p += len;
				len = 0;
				sscanf (p, "%*[^a-zA-Z]%n", &len);
				p += len;
				len = 0;
			}
		}
		
		int found = 0;
		for (int n = 0; n < N; n++) {
			if (act_hits[n] >= req_hits[n])
				printf (found++ ? ",%s" : "%s", cat_names[n].c_str ());
		}
		if (!found)
			printf ("SQF Problem.");

		printf ("\n");
	}

	return 0;
}

