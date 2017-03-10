#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

typedef vector<int> vi;
#define NONE (-1)

int find_fr (int a, vi &p, vi &r, vi &e)
{
	return ((p[a] == a) ? a : (p[a] = find_fr (p[a], p, r, e)));
}

int find_en (int a, vi &p, vi &r, vi &e)
{
	int e_a = e[find_fr (a, p, r, e)];

	if (e_a != NONE)
		e_a = find_fr (e_a, p, r, e);

	return e_a;
}

int are_en (int a, int b, vi &p, vi &r, vi &e)
{
	int p_a = find_fr (a, p, r, e);
	int p_b = find_fr (b, p, r, e);
	
	int e_a = find_en (p_a, p, r, e);
	int e_b = find_en (p_b, p, r, e);

	if (e_a == p_b) {
		assert (e_b == p_a);
		return 1;
	} else if (e_b == p_a) {
		assert (e_a == p_b);
		return 1;
	} else
		return 0;
}

int mk_fr (int a, int b, vi &p, vi &r, vi &e)
{
	int p_a = find_fr (a, p, r, e);
	int p_b = find_fr (b, p, r, e);

	if (are_en (a, b, p, r, e))
		return -1;
		
	int e_a = find_en (a, p, r, e);
	int e_b = find_en (b, p, r, e);

	if (p_a != p_b) {
		if (r[p_a] > r[p_b]) {
			p[p_b] = p_a;
			if (e_b != NONE)
				e[e_b] = p_a;
		} else {
			p[p_a] = p_b;
			if (e_a != NONE)
				e[e_a] = p_b;
			if (r[p_a] == r[p_b])
				r[p_b]++;
		}
	}
	
	if (e_a == NONE)
		e[p_a] = e_b;

	if (e_b == NONE)
		e[p_b] = e_a;

	if (e_a != NONE && e_b != NONE && e_a != e_b)
		return mk_fr (e_a, e_b, p, r, e);

	return 1;
}

int mk_en (int a, int b, vi &p, vi &r, vi &e)
{
	if (are_en (a, b, p, r, e))
		return 1;

	int p_a = find_fr (a, p, r, e);
	int p_b = find_fr (b, p, r, e);

	if (p_a == p_b)
		return -1;

	int e_a = find_en (a, p, r, e);
	int e_b = find_en (b, p, r, e);
	int retval = 1;
	
	if (e_a == NONE && e_b == NONE) {
		e[p_a] = p_b;
		e[p_b] = p_a;
		return 1;
	}

	if (e_a != NONE)
		retval = mk_fr (e_a, b, p, r, e);

	if (retval < 0)
		return -1;

	if (e_b != NONE)
		retval = mk_fr (e_b, a, p, r, e);

	if (retval < 0)
		return -1;

	return 1;
}

int are_fr (int a, int b, vi &p, vi &r, vi &e)
{
	int p_a = find_fr (a, p, r, e);
	int p_b = find_fr (b, p, r, e);

	return (p_a == p_b);
}

void init_ufds (vi &p, vi &r, vi &e)
{
	int len = p.size ();

	for (int i = 0; i < len; i++) {
		p[i] = i;
		r[i] = 0;
		e[i] = NONE;
	}
}

D(
void pr_vec (char *s, vi &v)
{
	int len = v.size ();

	printf ("%s = [ ", s);
	for (int i = 0; i < len; i++)
		printf ("%3d ", v[i]);
	printf ("]\n");
}
)

int
main ()
{
	int N;
	scanf ("%d", &N);
  const char* name[] = { NULL, 
														"Set Friends", 
														"Set Enemies", 
														"Are Friends?",
														"Are Enemies?" };

	vi p (N), r (N), e (N);
	
	int c, a, b;
	
	init_ufds (p, r, e);

	while (scanf ("%d %d %d", &c, &a, &b), c || a || b) {
		D( printf ("Operation : %s (%d, %d)\n", name[c], a, b); )
		if (c == 1) {
			if (mk_fr (a, b, p, r, e) < 0)
				puts ("-1");
		} else if (c == 2) {
			if (mk_en (a, b, p, r, e) < 0)
				puts ("-1");
		} else if (c == 3) {
			printf ("%d\n", are_fr (a, b, p, r, e));
		} else if (c == 4) {
			printf ("%d\n", are_en (a, b, p, r, e));
		}
		
		D(
		pr_vec ("p", p);
		pr_vec ("r", r);
		pr_vec ("e", e);
		)
	}

	return 0;
}
