#include <bits/stdc++.h>
using namespace std;

int
main ()
{
	int N, P;
	int rfp_num = 0;
	
	while (scanf ("%d%d", &N, &P), (N || P)) {
		for (int n = 0; n < N; n++)
			scanf (" %*[^\n]");
		
		vector<int> n_req_met;
		vector<string> name;
		vector<double> price;

		int max_nreq = 0;
		for (int p = 0; p < P; p++) {
			char str[100];
			double pr;
			int nreq;

			scanf (" %[^\n]", str);
			scanf ("%lf %d", &pr, &nreq);

			for (int j = 0; j < nreq; j++)
				scanf (" %*[^\n]");

			name.push_back (str);
			n_req_met.push_back (nreq);
			price.push_back (pr);

			if (nreq > max_nreq)
				max_nreq = nreq;
		}
		
		int ind = 0;
		double min_pr = DBL_MAX;
		for (int p = 0; p < P; p++) {
			if (n_req_met[p] == max_nreq) {
				if (price[p] < min_pr) {
					min_pr = price[p];
					ind = p;
				}
			}
		}
		if (rfp_num)
			printf ("\n");

		printf ("RFP #%d\n%s\n", ++rfp_num, name[ind].c_str ());
	}

	return 0;
}
