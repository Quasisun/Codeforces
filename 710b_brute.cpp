#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int x[300010];
int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x[i];
	}
	sort(x, x+n);
	cout << x[(n-1)/2] << endl;
}
	
