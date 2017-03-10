#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<long long int, int> umapll_t;


long long hash_name (char *name)
{
	long long h = 0LL;
	for (char *p = name; *p; p++)
		h = 26LL * h + (*p - 'a');

	return h;
}

int
main ()
{
	int N;
	bool first = true;
	while (scanf ("%d", &N) == 1) {
		umapll_t ind;
		vector<int> balance (N, 0);
		vector<string> name_list;
		
		for (int i = 0; i < N; i++) {
			char name[20];
			scanf (" %s", name);
			
			name_list.push_back (name);
			ind[hash_name (name)] = i;
		}

		for (int i = 0; i < N; i++) {
			char name[20];
			int amt, n;
			scanf (" %s %d %d", name, &amt, &n);

			int gift_amt, rem_amt;
			int giver;

			giver = ind[hash_name (name)];
			gift_amt = n ? amt / n : 0;
			rem_amt = n ? amt % n : amt;
			balance[giver] += rem_amt;
			balance[giver] -= amt;

			for (int j = 0; j < n; j++) {
				char name_fr[20];
				scanf (" %s", name_fr);

				int reciever = ind[hash_name (name_fr)];
				balance[reciever] += gift_amt;
			}
		}
			
		if (!first)
			printf ("\n");
		else
			first = false;

		for (int i = 0; i < N; i++) {
			int j = ind[hash_name ((char *)name_list[i].c_str ())];
			printf ("%s %d\n", name_list[i].c_str (), balance[j]);
		}
	}

	return 0;
}

