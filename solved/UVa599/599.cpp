#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 200

int dfs (vector<char> adj[], char st, bool visited[]) 
{
	stack<char> stk;
	if (!visited[st]) {
		visited[st] = true;
		stk.push (st);
	}

	int ct = 0;
	while (stk.size ()) {
		char u = stk.top ();
		stk.pop ();

		ct++;
		vector<char>::iterator it;
		for (it = adj[u].begin (); it != adj[u].end (); it++) {
			char v = *it;
			if (!visited[v]) {
				visited[v] = true;
				stk.push (v);
			}
		}
	}

	return ct;
}

int main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		bool visited['Z' + 1];
		bool valid['Z' + 1];
		vector<char> adj['Z' + 1];
		char line[MAXLLEN];

		for (char i = 'A'; i <= 'Z'; i++)
			valid[i] = visited[i] = false;

		while (fgets (line, MAXLLEN, stdin), *line != '*') {
			char st, end;
			sscanf (line, "(%c,%c)", &st, &end);
			adj[st].push_back (end);
			adj[end].push_back (st);
		}

		fgets (line, MAXLLEN, stdin);
		int l = strcspn (line, "\n");
		line[l] = ',';
		line[l + 1] = 0;
		char *p = line;
		int len;
		char c;
		while (!(len = 0) && sscanf (p, "%c,%n", &c, &len) == 1) {
			valid[c] = true;
			p += len;
		}

		int trees, acorns;
		trees = acorns = 0;
		for (char i = 'A'; i <= 'Z'; i++) {
			if (valid[i] && !visited[i]) {
				int ct = dfs (adj, i, visited);

				if (ct == 1)
					acorns++;
				else
					trees++;
			}
		}

		printf ("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}
	
	return 0;
}


