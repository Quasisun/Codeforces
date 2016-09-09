#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, x, y;
ll t[10000010];

ll solve(int a) {
	if(t[a] != -1) return t[a];
	ll ans;
	if(!(a & 1)) {
		ll c = solve(a/2);
		ans = min(c + y, c + (a/2) * x);
		t[a] = ans;
		return ans;
	} else {
		ll c = solve(a/2LL);
		ll d = solve(a/2LL+1LL);
		ans = min(min(c + y + x, c + (a/2LL + 1LL) * x), min(d+y+x, d+(a/2LL)*x));
		t[a] = ans;
		return ans;
	}
}
			
int main() {
	cin >> n >> x >> y;
	memset(t, -1, sizeof t);
	t[0] = 0;
	t[1] = (ll) x;
	cout << solve(n) << endl;
}
