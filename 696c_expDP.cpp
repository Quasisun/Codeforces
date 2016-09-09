#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

#define P 1000000007ull
#define INV2 500000004ull
#define INV3 333333336ull

int main() {
	ull k, p, q;
	cin >> k;
	ull a[k];
	for(int i=0; i<k; ++i) {
		cin >> a[i];
	}
	bool even = false;
	for(int i=0; i<k; ++i) {
		if ((a[i] % 2) == 0) {
			even = true;
			break;
		}
	}
	ull base, rem = 2;
	for(int i=0; i<k; ++i) {
		base = rem;
		for(int j=log2(a[i])-1; j>=0; --j) {
			rem = (rem * rem) % P;
			if(a[i] & (1ULL << j)) {
				rem = (rem * base) % P;
			} 
		}
	}
	q = rem * INV2 % P;
	if (even) {
		p = ((q + 1) % P) * INV3 % P;
	} else {
		p = ((q + P - 1) % P) * INV3 % P;
	}
	cout << p << "/" << q << endl;
}