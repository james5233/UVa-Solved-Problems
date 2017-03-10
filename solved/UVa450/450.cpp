#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

typedef struct pers_t {
	string store[7];
	string dept;
	int ind;
} pers_t;

typedef pair<string, int> psi;
typedef vector<psi> vpsi;

#define MAXSTR 300

int
main ()
{
	int n_depts;
	char str[MAXSTR];
	int ind = 0;
	vpsi lst;
	vector<pers_t> pst;
	int status;

	scanf ("%d ", &n_depts);
	for (int i = 0; i < n_depts; i++) {
		scanf ("%[^\n]", str);
		getchar ();
		string dept (str);
			
		D( printf ("DEBUG: Department is [%s]\n", dept.c_str ()); )

		while ((status = scanf ("%[^\n]", str)) != EOF) {
			getchar ();
			
			if (status != 1)
				break;
			
			D( printf ("DEBUG: String is [%s]\n", str); )
			pers_t p;
			p.store[0] = string (strtok (str, ","));
			D( printf ("DEBUG: Token is [%s]\n", p.store[0].c_str ()); )
			for (int j = 1; j < 7; j++) {
				p.store[j] = string(strtok (NULL, ","));
				D( printf ("DEBUG: Token is [%s]\n", p.store[j].c_str ()); )
			}
			p.dept = dept;
			p.ind = ind;

			lst.push_back (make_pair (p.store[2], ind));
			pst.push_back (p);
			ind++;
		}
	}

	sort (lst.begin (), lst.end ());
	vpsi::iterator it;

	for (it  = lst.begin (); it != lst.end (); it++) {
		for (int j = 0; j < 60; str[j++] = '-');
		str[60] = '\0';
		puts (str);
		
		D( printf ("DEBUG: it is [%s:%d]\n", it->first.c_str(), it->second); )
		pers_t p = pst[it->second];
		printf ("%s %s %s\n", p.store[0].c_str (),
			p.store[1].c_str (), p.store[2].c_str ());
		printf ("%s\n", p.store[3].c_str ());
		printf ("Department: %s\n", p.dept.c_str ());
		printf ("Home Phone: %s\n", p.store[4].c_str ());
		printf ("Work Phone: %s\n", p.store[5].c_str ());
		printf ("Campus Box: %s\n", p.store[6].c_str ());
	}

	return 0;
}
