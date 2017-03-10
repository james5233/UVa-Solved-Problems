#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int T;
	for (scanf ("%d", &T); T--;) {
		int N;
		scanf ("%d", &N);
		
		vector<int> fr (N), rt (N);

		for (int i = 0; i < N; i++)
			scanf ("%d", &fr[i]);

		for (int i = 0; i < N; i++)
			scanf ("%d", &rt[i]);
		
		vector<int> rt_sav = rt, fr_sav = fr;

		fr.push_back (-1);
		rt.push_back (-1);

		sort (fr.begin (), fr.end (), greater<int>() );
		sort (rt.begin (), rt.end (), greater<int>() );

		int m, M;
		int i_fr, i_rt;
	
		m = M = 0;
		i_fr = i_rt = 0;

		for (int i = 0; i < 2 *N;) {
			int mx = max (fr[i_fr], rt[i_rt]);
			
			m += mx;
			if (fr[i_fr] == rt[i_rt]) {
				i_fr++;
				i_rt++;
				i += 2;
			} else if (mx == fr[i_fr]) {
				i_fr++;
				i++;
			} else {
				i_rt++;
				i++;
			}
		}

		int H = max (fr[0], rt[0]);
		int arr[N][N][H];

		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				for (int z = 0; z < H; z++)
					arr[x][y][z] = 1;

		for (int x = 0; x < N; x++) {
			int Z = fr_sav[x];
			for (int z = H - 1; z >= Z; z--)
				for (int y = 0; y < N; y++)
					arr[x][y][z] = 0;
		}
		
		for (int y = 0; y < N; y++) {
			int Z = rt_sav[y];
			for (int z = H - 1; z >= Z; z--)
				for (int x = 0; x < N; x++)
					arr[x][y][z] = 0;
		}

		for (int x = 0; x < N; x++)
			for (int y = 0; y < N; y++)
				for (int z = 0; z < H; z++)
					M += arr[x][y][z];

		printf ("Matty needs at least %d blocks, and can add at most %d"
		" extra blocks.\n", m, M - m);
	}

	return 0;
}
