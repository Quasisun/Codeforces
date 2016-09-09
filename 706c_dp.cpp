#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef unsigned long long ull;

#define INF ULLONG_MAX-10
int n;
int c[100010];
ull dp[100010][2];
string s[100010], r[100010];

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> c[i];
	}
	for(int i=0; i<n; i++) {
		cin >> s[i];
		r[i] = s[i];
		for(int j=0; j<s[i].length(); j++) {
			r[i][s[i].length()-1-j] = s[i][j];
		}
	}
	dp[0][0] = 0;
	dp[0][1] = c[0];
	for(int i=1; i<n; i++) {
		dp[i][0] = INF;
		dp[i][1] = INF;
		if(dp[i-1][0] != -1 && !lexicographical_compare(s[i].begin(),s[i].end(),s[i-1].begin(),s[i-1].end())) {
			dp[i][0] = min(dp[i][0], dp[i-1][0]);
		}
		if(dp[i-1][1] != -1 && !lexicographical_compare(s[i].begin(),s[i].end(),r[i-1].begin(),r[i-1].end())) {
			dp[i][0] = min(dp[i][0], dp[i-1][1]);
		}
		if(dp[i-1][0] != -1 && !lexicographical_compare(r[i].begin(),r[i].end(),s[i-1].begin(),s[i-1].end())) {
			dp[i][1] = min(dp[i][1], dp[i-1][0]+c[i]);
		}
		if(dp[i-1][1] != -1 && !lexicographical_compare(r[i].begin(),r[i].end(),r[i-1].begin(),r[i-1].end())) {
			dp[i][1] = min(dp[i][1], dp[i-1][1]+c[i]);
		}
		if(dp[i][0] == INF) dp[i][0] = -1;
		if(dp[i][1] == INF) dp[i][1] = -1;
	}
	ull total = INF;
	if(dp[n-1][0] != -1) total = min(total, dp[n-1][0]);
	if(dp[n-1][1] != -1) total = min(total, dp[n-1][1]);

	if (total == INF) {
		cout << -1 << endl;
	} else {
		cout << total << endl;
	}
}

// #define NEG_INF = -2000000000

// int n;
// int o[100010];
// long long c[100010];
// string s[100010], r[100010];
// string cut = "";
// int main() {
// 	cin >> n;
// 	for(int i=0; i<n; i++) {
// 		cin >> c[i];
// 	}
// 	for(int i=0; i<n; i++) {
// 		cin >> s[i];
// 		r[i] = s[i];
// 		for(int j=0; j<s[i].length(); j++) {
// 			r[i][s[i].length()-1-j] = s[i][j];
// 		}
// 	}

// 	memset(o, -1, sizeof o);

// 	unsigned long long total = 0;
// 	for(int i=0; i<n; i++) {
		
// 		if(cut != "") {
// 			bool b5 = lexicographical_compare(s[i].begin(), s[i].end(), cut.begin(), cut.end());
// 			bool b6 = lexicographical_compare(r[i].begin(), r[i].end(), cut.begin(), cut.end());
// 			if(b5 && b6) {
// 				cout << -1 << endl;
// 				return 0;
// 			}
// 			if(b5) {
// 				o[i] = 1;
// 				cut = r[i];
// 				continue;
// 			}
// 			if(b6) {
// 				o[i] = 0;
// 				cut = s[i];
// 				continue;
// 			}
// 		}

// 		if(i == n-1) {
// 			o[i] = 0;
// 			continue;
// 		}
// 		bool b1 = lexicographical_compare(s[i+1].begin(), s[i+1].end(), s[i].begin(), s[i].end());
// 		bool b2 = lexicographical_compare(r[i+1].begin(), r[i+1].end(), s[i].begin(), s[i].end());
// 		bool b3 = lexicographical_compare(s[i+1].begin(), s[i+1].end(), r[i].begin(), r[i].end());
// 		bool b4 = lexicographical_compare(r[i+1].begin(), r[i+1].end(), r[i].begin(), r[i].end());
		
// 		if(!lexicographical_compare(r[i].begin(), r[i].end(), s[i].begin(), s[i].end())) {
// 			o[i] = 0;
// 			cut = s[i];
// 			continue;
// 		}
// 		if(c[i] == 0) {
// 			o[i] = 1;
// 			cut = r[i];
// 			continue;
// 		}
// 		if(!b1 && !b2) {
// 			o[i] = 0;
// 			cut = s[i];
// 			continue;
// 		}
// 		if(b1 && b2) {
// 			o[i] = 1;
// 			cut = r[i];
// 			continue;
// 		}
// 		if(b1) {
// 			if(c[i+1] < c[i]) {
// 				string temp = s[i+1];
// 				s[i+1] = r[i+1];
// 				r[i+1] = temp;
// 				total += c[i+1];
// 				c[i+1] = c[i] - c[i+1];
// 			} else {
// 				total += c[i];
// 				c[i+1] -= c[i];
// 			}
// 			continue;
// 		}
// 		if(b2) {
// 			c[i+1] += c[i];
// 			continue;
// 		}
// 		cout << "BROKEN" << endl;
// 	}

	
// 	for(int i=0; i<n; i++) {
// 		// cout << o[i] << endl;
// 		if(o[i] == 1) {
// 			total += c[i];
// 		}
// 	}
// 	cout << total << endl;
// }