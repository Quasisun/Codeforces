#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000

int n, a;
int c[100010];

int dist(int l, int r) {
	if (a<c[l]) {
		return c[r]-a;
	} else if (a>c[r]) {
		return a-c[l];
	} 
	return min(c[r]-a, a-c[l]) + c[r] - c[l];
}
int main() {
	cin >> n >> a;
	for(int i=0; i<n; i++) {
		cin >> c[i];
	}
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}
	sort(c, c+n);
	cout << min(dist(0,n-2), dist(1,n-1)) << endl;
}
