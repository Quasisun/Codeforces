#include <bits/stdc++.h>
#include <iostream>

using namespace std; 

int main() {
	int n, m, lo, hi, mid, dist, max_dist, val;
	cin >> n >> m;
	int homes[n];
	int towers[m];
	for(int i=0; i<n; ++i) {
		cin >> homes[i]; 
	}
	for(int i=0; i<m; ++i) {
		cin >> towers[i];
	}

	lo = 0;
	max_dist = 0;
	for(int i=0; i<n; ++i) {
		hi = m;
		val = homes[i];
		if (val < towers[0]) {
			dist = towers[0] - val;
		} else if (val > towers[m-1]) {
			dist = val - towers[m-1];
		} else {
			while (lo < hi - 1) {
				mid = lo + (hi-lo)/2;
				if (towers[mid] <= val) {
					lo = mid;
				} else {
					hi = mid;
				}
			}
			dist = min(val - towers[lo], towers[hi] - val);
		}
		if (dist > max_dist) {
			max_dist = dist;
		}
	}
	cout << max_dist << endl;
}