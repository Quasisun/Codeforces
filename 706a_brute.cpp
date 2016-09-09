#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n;
double a,b,t=100000000.,x,y,v;
int main() {
	cin >> a >> b >> n;
	for(int i=0; i<n; i++) {
		cin >> x >> y >> v;
		t = min(t, sqrt((x - a) * (x-a) + (y-b) * (y-b)) / v);
	}
	cout << setprecision(10) << t << endl;
}