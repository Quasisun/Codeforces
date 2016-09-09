#include <bits/stdc++.h>

using namespace std;

int n,k,x,nim;
int get(int sz) {
	if(k==0) {
		if(sz == 1) return 1;
		if(sz == 2) return 2;
		return (sz % 2 == 0);
	} else {
		if(sz == 1) return 1;
		if(sz == 2) return 0;
		if(sz == 3) return 1;
		if(sz == 4) return 2;
		if(sz % 2 == 1) return 0;
		if(get(sz/2) == 1) return 2;
		return 1;
	}
}
int main() {
	cin >> n >> k;
	k%=2;
	
	for(int i=0; i<n; i++) {
		cin >> x;
		nim^=get(x);
	}
	if(nim) {
		cout << "Kevin" << endl;
	} else {
		cout << "Nicky" << endl;
	}
}
		

	
