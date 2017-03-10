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
	scanf ("%d ", &T);

	for (int t = 1; t <= T; t++) {
		char line[MAXLLEN], w[MAXLLEN];
		unordered_map <string, int> id_of_word;
		vector<int> id_at_posn;

		int n_uniq_words, n_words;
		n_uniq_words = n_words = 0;

		while (fgets (line, MAXLLEN, stdin)) {
			if (strstr (line, "END"))
				break;

			char *p = line;
			int len;
			
			len = 0;
			sscanf (p, "%*[^a-z]%n", &len);
			p += len;

			while (!(len = 0) && sscanf (p, "%[a-z]%n", w, &len) == 1) {
				unordered_map<string, int>::iterator it = id_of_word.find (w);

				if (it == id_of_word.end ()) {
					id_at_posn.push_back (n_uniq_words);
					id_of_word[w] = n_uniq_words++;
				} else {
					id_at_posn.push_back (it->second);
				}

				n_words++;
				
				p += len;
				len = 0;
				sscanf (p, "%*[^a-z]%n", &len);
				p += len;
			}
		}

		int p, q, min_p, min_q, nr;

		p = q = 0;
		min_p = 0;
		min_q = n_words;
		nr = 0;
		
		vector<int> ct_of_id (n_uniq_words, 0);

		while (p < n_words && q <= n_words) {
			D( printf ("[p = %d \tq = %d \tnr = %d]\n", p, q, nr); )
			if (nr == n_uniq_words) {
				if (q - p < min_q - min_p) {
					min_p = p;
					min_q = q;
					D( printf ("Updating min_p and min_q\n"); )
				}
				if (ct_of_id[id_at_posn[p]]-- == 1) {
					nr--;
					D( printf ("Lost a unique word\n"); )
				}
		
				p++;
			} else {
				if (q < n_words && ct_of_id[id_at_posn[q]]++ == 0) {
					nr++;
					D( printf ("Gained a new word\n"); )
				}

				q++;
			}
		}

		printf ("Document %d: %d %d\n", t, min_p + 1, min_q);
	}

	return 0;
}
