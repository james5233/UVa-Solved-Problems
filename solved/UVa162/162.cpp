#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	while (true) {
		deque<char> player[3];
		
		int j = 2;
		for (int i = 0; i < 52; i++) {
			char str[20];
			scanf (" %s", str);

			if (str[0] == '#')
				return 0;
			player[j].push_back (str[1]);
			
			j = !(j - 1) + 1;
		}

		deque<char> stk;

		int turn = 1;
		int rem = 0;
		int winner, exposer;

		while (1) {
			char card;

			if (!rem) 
				turn = !(turn - 1) + 1;

			if (player[turn].size () == 0) {
				winner = !(turn - 1) + 1;
				break;
			}

			card = player[turn].back ();
			player[turn].pop_back ();

			stk.push_back (card);

			if (card == 'A') {
				rem = 4;
				exposer = turn;
				turn = !(turn - 1) + 1;
			} else if (card == 'K') {
				rem = 3;
				exposer = turn;
				turn = !(turn - 1) + 1;
			} else if (card == 'Q') {
				rem = 2;
				exposer = turn;
				turn = !(turn - 1) + 1;
			} else if (card == 'J') {
				rem = 1;
				exposer = turn;
				turn = !(turn - 1) + 1;
			} else {
				if (rem != 0) {
					rem--;

					if (!rem) {
						while (!stk.empty ()) {
							char c = stk.front ();
							stk.pop_front ();

							player[exposer].push_front (c);
						}

						turn = !(exposer - 1) + 1;
					}
				}
			}
		}

		printf ("%d%3d\n", winner, (int) player[winner].size ());
	}
	return 0;
}
		

			

