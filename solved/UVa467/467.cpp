#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define D(x) x
#else
	#define D(x)
#endif

#define MK_TRI(x, y, z) make_pair (make_pair (x, y), z)
#define TIME(x) ((x).first.first)
#define STATE(x) ((x).first.second)
#define PERIOD(x) ((x).second)

#define ON 1
#define OFF 0

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<piii> vpiii;
typedef priority_queue<piii, vpiii, greater<piii> > pqpiii;

int
main ()
{
	int status = 1, set_num = 1;
	do {
		int d, N;
		char c[20];
		pqpiii pq;
		
		N = 0;
		while (status = scanf ("%d%[^0-9]", &d, c), status == 2) {
			pq.push (MK_TRI (d - 5, OFF, d));
			N++;

			if (strchr (c, '\n') != NULL)
				break;
		}

		if (status == EOF)
			break;
		
		int ct = N;
		int tm;

		do {
			tm = TIME (pq.top());
			
			while (tm == TIME (pq.top())) {
				piii n = pq.top ();
				pq.pop ();
				if (STATE(n) == OFF) {
					ct--;
					pq.push (MK_TRI (tm + 5 + PERIOD(n), ON, PERIOD(n)));
					D( printf ("[%d] Light turns OFF.\n", tm); )
				} else {
					ct++;
					pq.push (MK_TRI (tm + PERIOD(n) - 5, OFF, PERIOD(n)));
					D( printf ("[%d] Light turns ON.\n", tm); )
				}

				D( printf ("[%d] count = %d.\n", tm, ct); )
			}

		} while (ct < N && tm < 3600);

		if (ct == N) {
			printf ("Set %d synchs again at %d minute(s) and %d second(s) after "
				"all turning green.\n", set_num, tm/60, tm%60);
		} else {
			printf ("Set %d is unable to synch after one hour.\n", set_num);
		}

		set_num++;
	} while (true);

	return 0;
}

