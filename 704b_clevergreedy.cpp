#include <bits/stdc++.h>
#include <iostream>
#include <cstddef>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

#define INF 2000000000000000000ll
ll x[5010], a[5010], b[5010], c[5010], d[5010], nxt[5010];

ll getDist(int i, int j) {
	if(i>j) return x[i]-x[j]+c[i]+b[j];
	return x[j]-x[i]+d[i]+a[j];
}
int main() {
	int n, s, e;
	cin >> n >> s >> e;

	for(int i=1; i<=n; i++) {
		cin >> x[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> b[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> c[i];
	}
	for(int i=1; i<=n; i++) {
		cin >> d[i];
	}

	ll total = getDist(s,e);
	int min_it;
	nxt[s] = e;
	ll delta, min_delta = INF;
	for(int i=1; i<=n; i++) {
		if(i != s && i != e) {
			min_delta = INF;
			for(int it=s; it!=e; it=nxt[it]) {
				delta = getDist(it,i) + getDist(i,nxt[it]) - getDist(it, nxt[it]);
				if(delta < min_delta) {
					min_delta = delta;
					min_it = it;
				} 
			}
			nxt[i] = nxt[min_it];
			nxt[min_it] = i;
			total += min_delta;
		}
	}
	// for(int it=s; it!=e; it=nxt[it]) {
	// 	cout << it << endl;
	// }
	cout << total << endl;
}