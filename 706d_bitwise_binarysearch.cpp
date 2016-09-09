#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int q,x,a;
char c;
multiset<int> ms;

int main() {
	cin >> q;
	ms.insert(0);
	for(int i=0; i<q; i++) {
		cin >> c >> x;
		if (c == '+') {
			ms.insert(x);
			continue;
		}
		if (c == '-') {
			ms.erase(ms.find(x));
			continue;
		}
		a=0;
		for(int k = 30; k>=0; k--) {
			a |= (~x & 1<<k);
			auto it = ms.lower_bound(a);
			if (it == ms.end() || *it >= a + (1<<k)) {
				a ^= 1<<k;
				//cout << "switch";
			}
			//cout << a << " " << *it << endl;
		}
		cout << (a ^ x) << endl;
	}
}