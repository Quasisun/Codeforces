#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int,int> ii;
typedef pair<double,int> di;

ii a, b, t, nxt;
int n;
double tot;
vector<di> A;
vector<di> B;
double dist(ii c, ii d) {
	return sqrt(((double) c.first - (double) d.first) * ((double) c.first - (double) d.first) +  ((double) c.second - (double) d.second) * ((double) c.second - (double) d.second));
}
int main() {
	cin >> a.first >> a.second >> b.first >> b.second >> t.first >> t.second;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> nxt.first >> nxt.second;
		A.push_back(di((dist(nxt,a) - dist(nxt,t)),i));
		B.push_back(di((dist(nxt,b) - dist(nxt,t)),i));
		tot += dist(nxt,t) * 2;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	double mina = A[0].first;
	double minb = B[0].first;

	if(n == 1 || (mina >= 0. && minb >= 0.)) {
		cout << setprecision(100) << tot + min(mina, minb) << endl;
		return 0;
	}
	if(A[0].second != B[0].second) {
		cout << setprecision(100) << tot + min(mina, 0.) + min(minb, 0.) << endl;
		return 0;
	}

	cout << setprecision(100) << tot + min(mina + min(0., B[1].first), minb + min(0., A[1].first)) << endl;
	return 0;
}