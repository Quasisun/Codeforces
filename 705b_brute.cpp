#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	int ans;
	if(a[0] % 2 == 0) {
		ans = 0;
	} else {
		ans = 1;
	}
	for(int i=1; i<n; i++) {
		cout << ans+1 << endl;
		if(a[i] % 2 == 0) {
			ans = (ans + 1) % 2;
		}
	}
	cout << ans+1 << endl;
}