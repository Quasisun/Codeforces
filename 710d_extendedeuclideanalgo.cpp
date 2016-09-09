#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll gcd(ll a, ll b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

inline ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

ll a1,b1,a2,b2,L, R;
ll s[777777], t[777777], a[777777];
ll r,q;
int main() {
	cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
	s[0]=1; s[1]=0; t[0]=0; t[1]=1; a[0]=max(a1,a2); a[1]=min(a1,a2);
	int i=0;
	while(a[i] % a[i+1] != 0) {
		r = a[i] % a[i+1];
		q = a[i] / a[i+1];
		a[i+2] = r;
		s[i+2] = s[i] - q * s[i+1];
		t[i+2] = t[i] -q * t[i+1];
		i++;
	}
	if((b1 - b2) % a[i+1] != 0) {
		cout << 0 << endl;
		return 0;
	}
	ll gap = (b1-b2) / a[i+1];
	ll first;

	if(a1 > a2) {
		first = b2 + t[i+1] * a2 * gap;
	} else {
		first = b2 + s[i+1] * a2 * gap;
	}
	//cout << first << endl;
	ll c = lcm(a1,a2);
	L = max(max(b1,b2),L);
	if(L > R) {
		cout << 0 << endl;
		return 0;
	}
	ll x = (first % c + c) % c;
	ll y = (L % c + c) % c;
	ll z = (R % c + c) % c;
	if((z >= y && x <=z && x >=y) || (z<y && (x >= y || x <=z))) {
		cout << (R-L) / c + 1 << endl;
	} else {
		cout << (R-L) / c << endl;
	}
	
	
	
}
	
