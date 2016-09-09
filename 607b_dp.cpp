#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define INF 2000000000
/*
TRICK: Can do bottom-up DP on substrings of a string by iterating through like
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
    	recursion for substring(i to j)
    }
  }

  Also for this problem, you can do straight DP on all substrings, instead of checking c[i] == c[a]
*/
int n;
int c[510];
int dp[510][510];
int solve(int a, int b) {
	// for(int i=0; i<=n; i++) {
	// 	for(int j=0; j<=n;  j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "-----" << endl;
	if (dp[a][b] != -1) return dp[a][b];
	int ans = solve(a+1,b)+1;
	for(int i=a+1; i<b; i++) {
		if (c[i] == c[a]) {
			if(i == a+1) {
				ans = min(ans, 1 + solve(i+1, b));
			} else {
				ans = min(ans, solve(a+1, i) + solve(i+1, b));
			}
		}
	}
	dp[a][b] = ans;
	return ans;
}
int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> c[i];
	}
	memset(dp, -1, sizeof dp);
	for(int i=0; i<=n; i++) {
		dp[i][i] = 0;
	}
	cout << solve(0,n) << endl;
}