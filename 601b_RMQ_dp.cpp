#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef unsigned long long ull;

int n, q, x, y;
ull a[100010];
int maxi[100010][17];

int get_maxi(int x, int y) {
	int p = log2(y-x);
	int w = maxi[x][p];
	int z = maxi[y - (1<<p)][p];
	if(a[w] >= a[z]) {
		return w;
	} 
	return z;
}

ull solve(int x, int y) {
	if(y==x) return 0;
	if(y-x == 1) return a[x];
	int z = get_maxi(x,y);
	return (ull) a[z] * (ull) (y-z) * (ull)(z - x +1) + solve(x,z) + solve(z+1,y);
}

int main() {
	cin >> n >> q >> x;
	for(int i=1; i<n; i++) {
		cin >> y;
		a[i] = abs(y-x);
		x=y;
	}
	for(int j=1; j<n; j++) {
		maxi[j][0] = j;
	}
	for(int i=1; i<=log2(n); i++) {
		for(int j=1; j<n; j++) {
			if(j+pow(2,i) <= n) {
				if(a[maxi[j][i-1]] >= a[maxi[j+ (1<<(i-1))][i-1]]) {
					maxi[j][i] = maxi[j][i-1];
				} else {
					maxi[j][i] = maxi[j+ (1<<(i-1))][i-1];
				}
			}
		}
	}
	// for(int i=0; i<=log2(n); i++) {
	// 	for(int j=1; j<n; j++) {
	// 		cout << maxi[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }

	for(int k=0; k<q; k++) {
		cin >> x >> y;
		cout << solve(x,y) << endl;
	}
}