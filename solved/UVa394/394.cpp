#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<string, int> umapsi_t;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vpii> vvpii;

int main ()
{
	int N, R;
	umapsi_t ind;

	scanf ("%d%d", &N, &R);
	vi base, word, dim;
	vvpii bounds (N);
	vvi C (N);

	for (int n = 0; n < N; n++) {
		char name[20];
		scanf (" %s", name);
		ind[name] = n;
		
		int b, w, d;
		scanf ("%d%d%d", &b, &w, &d);
		base.push_back (b);
		word.push_back (w);
		dim.push_back (d);
		
		bounds[n].push_back (make_pair (0, 0));
		for (int i = 1; i <= d; i++) {
			int lo, hi;
			scanf ("%d%d", &lo, &hi);

			bounds[n].push_back (make_pair (lo, hi));
		}

		C[n].resize (d + 1, 0);
		C[n][d] = w;
		C[n][0] = C[n][d] * bounds[n][d].first;
		for (int i = d - 1; i >= 1; i--) {
			C[n][i] = C[n][i+1] * (bounds[n][i+1].second - 
			                       bounds[n][i+1].first + 1);
			C[n][0] += C[n][i] * bounds[n][i].first;
		}
		C[n][0] = base[n] - C[n][0];
	}
	
	for (int r = 0; r < R; r++) {
		char name[20];
		vi k;
		scanf (" %s", name);

		int n = ind[name];
		int res = C[n][0];
		for (int i = 1; i <= dim[n]; i++) {
			int j;
			scanf ("%d", &j);
			res += C[n][i] * j;

			k.push_back (j);
		}

		printf ("%s[%d", name, k[0]);
		for (int i = 1; i < dim[n]; i++)
			printf (", %d", k[i]);
		printf ("] = %d\n", res);
	}

	return 0;
}
