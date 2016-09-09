#include <bits/stdc++.h>
#include <iostream>

using namespace std; 
#define INF 100000000000
typedef unsigned long long ull;


int main() {
	int n;
	ull k;
	cin >> n >> k;
	int f[42][n];
	ull s[42][n];
	ull m[42][n];
	for (int i=0; i<n; ++i) {
		cin >> f[0][i];
	}
	for (int i=0; i<n; ++i) {
		cin >> s[0][i];
	}
	for (int i=0; i<n; ++i) {
		m[0][i] = s[0][i];
	}
	for (int j=1; j<42; j++) {
		for(int i=0; i<n; i++) {
			f[j][i] = f[j-1][f[j-1][i]];
			s[j][i] = s[j-1][i] + s[j-1][f[j-1][i]];
			m[j][i] = min(m[j-1][i], m[j-1][f[j-1][i]]);
		}
	}

	int pos;
	ull sum, mini;
	for(int i=0; i<n; i++) {
		pos = i;
		sum = 0;
		mini = INF;
		for(int j=0; j<42; j++) {
			if (k & (1LL << j)) {
				sum += s[j][pos];
				mini = min(mini, m[j][pos]);
				pos = f[j][pos];
			}
		}
		cout << sum << " " << mini << endl;
	}
}