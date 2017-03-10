#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

typedef unordered_map<string, int> umapsi;

int
main ()
{
	umapsi mp;
	umapsi::iterator it;
	char word[50];
	int n_words = 0;

	while (scanf ("%[^,.:;!?\"()\n\t ]", word), 
	strcmp (word, "****END_OF_INPUT****")) {
		scanf ("%*[,.:;!?\"()\n\t ]");

		if (!strcmp (word, "****END_OF_TEXT****")) {
			double E, E_rel, E_max;
			
			E_max = log10 (n_words);

			E = 0.0;
			for (it = mp.begin (); it != mp.end (); it++) {
				E += it->second * (E_max - log10 (it->second));
			}
			E /= n_words;
			E_rel = (E * 100.0) / E_max;

			printf ("%d %.1lf %.0lf\n", n_words, E, E_rel);

			mp.clear ();
			n_words = 0;
			continue;
		}

		for (char *p = word; *p; p++)
			*p = tolower (*p);

		D( printf ("DEBUG: [%s]\n", word); )
		
		if ((it = mp.find (word)) != mp.end ()) 
			it->second++;
		else
			mp[word] = 1;
		
		n_words++;
	}

	return 0;
}




