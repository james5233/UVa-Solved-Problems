#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define MAXLINE 400

typedef pair<char, char> pcc;
typedef stack<pcc> spcc;
typedef vector<spcc> vspcc;

#define MATCHES(a, b) (((a).first == (b).first) || \
											 ((a).second == (b).second))

int
main ()
{
	char str[MAXLINE + 1];

	while (fgets (str, MAXLINE, stdin), *str != '#') {
		vspcc l (3);
		l[0].push (make_pair ('x', 'x'));
		l[1].push (make_pair ('y', 'y'));
		l[2].push (make_pair ('z', 'x'));
	
		int len = strlen (str);
		str[len - 1] = ' ';

		fgets (str + len, MAXLINE, stdin);
		
		char *p = str;
		for (int i = 0; i < 52; i++) {
			char c[4]; int end;
			sscanf (p, " %s%n", c, &end);
			p += end;

			D (printf ("Card is %c%c\n", c[0], c[1]); )
			
			l.push_back (spcc ());
			(l.end() - 1)->push (make_pair (c[0], c[1]));
			vspcc::iterator it;
			
			bool change;
			do {
				change = false;
				for (it = l.begin () + 3; it != l.end (); it++) {
					pcc from_top = it->top ();
					vspcc::iterator to = it - 3;
					pcc to_top = to->top ();

					if (MATCHES (from_top, to_top)) {
						it->pop ();
						to->push (from_top);
						change = true;

						D( printf ("Card %c%c moved over card %c%c\n", from_top.first, 
							from_top.second, to_top.first, to_top.second); )

						if (it->empty ())
							l.erase (it);

						break;
					}

					to = it - 1;
					to_top = to->top ();
					
					if (MATCHES (from_top, to_top)) {
						it->pop ();
						to->push (from_top);
						change = true;

						if (it->empty ())
							l.erase (it);

						break;
					}
				}
			} while (change);
		}

		int n_stk = l.size () - 3;
		printf ("%d pile%sremaining:", n_stk, (n_stk == 1) ? " " : "s ");
		
		vspcc::iterator it;
		for (it = l.begin () + 3; it != l.end (); it++)
			printf (" %d", (int) (it->size ()));
		printf ("\n");
	}

	return 0;
}






