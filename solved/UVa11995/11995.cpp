#include <bits/stdc++.h>
using namespace std;

#define PUSH(_cont, _ind) do {\
if (valid[_ind])\
	_cont.push (num);\
} while (0)

#define POP(_cont, _ind, _func) do {\
if (valid[_ind]) {\
	if (_cont.size () && _cont._func () == num)\
		_cont.pop ();\
	else\
		valid[_ind] = 0;\
}\
} while (0)

int
main ()
{
	int N;
	while (scanf ("%d", &N) == 1) {
		stack<int> stk;
		queue<int> q;
		priority_queue<int> pq;
		const char name[][20] = {"stack", "queue", "priority queue" };

		int valid[] = { 1, 1, 1 };
		
		for (int i = 0; i < N; i++) {
			int cmd, num;
			scanf ("%d%d", &cmd, &num);

			if (cmd == 1) {
				PUSH (stk, 0);
				PUSH (q, 1);
				PUSH (pq, 2);
			} else if (cmd == 2) {
				POP (stk, 0, top);
				POP (q, 1, front);
				POP (pq, 2, top);
			}
		}

		int sum = valid[0] + valid[1] + valid[2];
		int ind = valid[0] * 0 + valid[1] * 1 + valid[2] * 2;

		if (sum == 0)
			printf ("impossible\n");
		else if (sum == 1)
			printf ("%s\n", name[ind]);
		else 
			printf ("not sure\n");

	}
	return 0;
}

