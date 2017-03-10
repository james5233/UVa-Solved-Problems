#include <bits/stdc++.h>
using namespace std;

#define MAXLLEN 120

int 
main()
{
	int N;
	scanf ("%d", &N);
	while (getchar () != '\n');
	
	unordered_map<string, string> slogan;
	char line[MAXLLEN];

	for (int i = 0; i < N; i++) {
		string st, end;
		
		fgets (line, MAXLLEN, stdin);
		line[ strcspn (line, "\n") ] = 0;
		st = line;
		
		fgets (line, MAXLLEN, stdin);
		line[ strcspn (line, "\n") ] = 0;
		slogan[st] = line;
	}

	int M;
	scanf ("%d", &M);
	while (getchar () != '\n');

	for (int i = 0; i < M; i++) {
		fgets (line, MAXLLEN, stdin);
		line[ strcspn (line, "\n") ] = 0;

		printf ("%s\n", slogan[line].c_str ());
	}

	return 0;
}


