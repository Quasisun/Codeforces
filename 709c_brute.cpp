#include <bits/stdc++.h>

using namespace std;

string s;
int main() {
	cin >> s;
	int i=0;
	while(i<s.length() && s[i] == 'a') i++;
	if(i == s.length()) {
		s[i-1] = 'z';
		cout << s << endl;
		return 0;
	}
	int j=i;
	while(j<s.length() && s[j] != 'a') {
		s[j]--;
		j++;
	}
	cout << s << endl;
}
