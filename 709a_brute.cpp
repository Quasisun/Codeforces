#include <bits/stdc++.h>

using namespace std;

int n, b, d, x, sum, ct;
int main() {
	cin >> n >> b >> d;
	for(int i=0; i<n; i++) {
		cin >> x;
		if(x <= b) {
			sum += x;
			if (sum > d) {
				sum = 0;
				ct++;
			}
		}
	}
	cout << ct << endl;
}
