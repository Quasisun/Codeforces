#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a,b,c,d,x,y,cur;
string s="";
int main() {
	cin >>a >>b >> c >> d;
	x = (a==0) ? 0 : sqrt(2*a) + 1;
	y = (d==0) ? 0 : sqrt(2*d) + 1;
	if(x * (x-1) != 2*a || y * (y-1) != 2*d) {
		cout << "Impossible" << endl;
		return 0;
	}
	if(x == 0 && b+c != 0) x=1;
	if(y == 0 && b+c != 0) y=1;
	if(x+y == 0) {
		cout << "0" << endl;
		return 0;
	}
	if((x+y)*(x+y-1) != 2*(a+b+c+d)) {
		cout << "Impossible" << endl;
		return 0;
	}
	cur = x*y;
	ll i=0;
	while(cur > b) {
		cur -= y;
		i++;
	}
	ll j=b-cur;
	for(int q=0; q<x-i; q++){
		s += "0";
	}
	for(int q=0; q<y-j; q++){
		s += "1";
	}
	if(i > 0) s += "0";
	for(int q=0; q<j; q++) {
		s += "1";
	}
	for(int q=0; q<i-1; q++) {
		s += "0";
	}
	cout << s << endl;
}
	
