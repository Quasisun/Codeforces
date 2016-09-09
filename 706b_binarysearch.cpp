#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, q, m, lo, hi, mid;
int x[100010];

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x[i];
	}
	sort(x, x+n);
	cin >> q;
	for(int i=0; i<q; i++) {
		cin >> m;
		if (m < x[0]) {
			cout << 0 << endl;
			continue;
		}
		lo = 0;
		hi = n;
		while(lo < hi - 1) {
			mid = lo + (hi-lo)/2;
			if(x[mid] <= m) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << hi << endl;
	}
}