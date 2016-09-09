#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define INF 2000000000
typedef pair<int,int> ii;

int n,c,lo,hi,mid,x,y;
vector<ii> b(100010);
int dp[100010];
int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		b[i] = ii(x,y);
	}
	sort(b.begin(), b.begin()+n);
	dp[0] = 0;
	for(int i=1; i<n; i++) {
		c = b[i].first - b[i].second;
		if (c <= b[0].first) {
			dp[i] = i;
		} else {
			lo = 0;
			hi = i;
			while(lo < hi-1) {
				mid = lo + (hi - lo)/2;
				if(b[mid].first < c) {
					lo = mid;
				} else {
					hi = mid;
				}
			}
			dp[i] = dp[lo] + i - hi;
		}
	}
	int minb = n;
	for(int i=0; i<n; i++) {
		minb = min(minb, dp[i] + n - 1 - i);
	}
	cout << minb << endl;
}