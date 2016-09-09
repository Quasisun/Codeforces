#include <bits/stdc++.h>

using namespace std;

int n,x;
int a[49][49];

int main() {
	cin >> n;
	x = n/2;
	for(int i=0; i<n; i++) {
		a[x][i] = 1;
		a[i][x] = 1;
	}
	for(int i=0; i<x; i++) {
		for(int j=i+1; j<x; j++) {
			a[i][j] = 1;
			a[i][n-1-j] = 1;
			a[n-i-1][j] = 1;
			a[n-i-1][n-1-j] = 1;
		}
	}
	int oc = 1, ec=2;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if( j != 0) cout << " ";
			if(a[i][j] == 1) {
				cout << oc;
				oc +=2;
			} else {
				cout << ec;
				ec +=2;
			}
		}
		cout << endl;
	}
}
	

