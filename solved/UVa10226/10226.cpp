#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	
	for (scanf ("%d%*[\n]", &T); T--;) {
		map<string, int> ct;
		string s;
		int n_trees = 0;
		
		while (getline (cin, s)) {
			if (s == "")
				break;
			//cout << "[" << s << "]" << endl;
			ct[s]++;
			n_trees++;
		}
		
		if (n_trees) {
			map<string, int>::iterator it;
			for (it = ct.begin (); it != ct.end (); it++) 
				printf ("%s %.4lf\n", it->first.c_str (), (it->second * 100.0)/n_trees);
		}
		
		if (T)
			printf ("\n");
	}
}
