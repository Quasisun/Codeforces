#include <bits/stdc++.h>
#include <iostream>

using namespace std; 

typedef unsigned long long ull;

int main() {
	ull d, k, a, b, t, q, r;
	cin >> d >> k >> a >> b >> t;
	if (k >= d) {
		cout << a * d << endl;
		return 0;
	} 
	if (k*a + t >= k*b) {
		cout << a * k + b * (d-k) << endl;
		return 0;
	}
	q = d/k;
	r = d % k;
	if (a * r + t <= r*b) {
		cout << a * d + q * t << endl;
		return 0;
	}
	cout << a * q * k + (q-1) * t + r * b << endl;
	return 0;
}