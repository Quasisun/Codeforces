#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

int n, a, b, T;
string orient;

int get_time(int i) {
	if(orient[i] == 'w') {
		return b + 1;
	}
	return 1;
}

int binary_search(int arr[], int time) {
	int lo, hi, mid;
	lo = 0;
	hi = n;
	while(lo < hi - 1) {
		mid = lo + (hi-lo)/2;
		if (time >= arr[mid]) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return lo;
}

int main() {
	cin >> n >> a >> b >> T;
	cin >> orient;

	int left[n];
	int right[n];

	left[0] = 0;
	right[0] = 0;
	for(int i=1; i<n; i++) {
		left[i] = get_time(n-i) + a + left[i-1];
		right[i] = get_time(i) + a + right[i-1];
	}
	// for(int i=0; i<n; i++) cout << left[i] << " ";
	// cout << endl;
	// for(int i=0; i<n; i++) cout << right[i] << " ";
	// cout << endl;

	int res = 0, first, max_num = 0;
	for(int i=0; i<n; i++) {
		first = get_time(0) + right[i];
		if (first + a * i < T) {
			res = min(n, binary_search(left, T - (first + a * i)) + i + 1);
		} else if (first <= T) {
			res = i + 1;
		}
		if (res>max_num) max_num=res;
	}
	for(int i=0; i<n; i++) {
		first = get_time(0) + left[i];
		if (first + a * i < T) {
			res = min(n, binary_search(right, T - (first + a * i)) + i + 1);
		} else if (first < T) {
			res = i + 1;
		}
		if (res>max_num) max_num=res;
	}

	cout << max_num << endl;
}