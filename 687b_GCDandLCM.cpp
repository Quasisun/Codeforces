#include <bits/stdc++.h>

using namespace std;

inline int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

inline int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int l = 1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    int g = gcd(x, k);
    l = lcm(l, g);
  }
  puts(l == k ? "Yes" : "No");
  return 0;
}
// #include <bits/stdc++.h>
// #include <iostream>

// using namespace std;

// typedef long long ll;

// #define INF 2000000000000000000ll

// int n,k,x,c,t;
// vector<int> kp;
// int main() {
// 	cin >> n >> k;
// 	if(k == 1) {
// 		cout << "Yes" << endl;
// 		return 0;
// 	}
// 	t=k;
// 	if(k%2 == 0) {
// 		c=1;
// 		while(k % 2 == 0) {
// 			c *= 2;
// 			k /= 2;
// 		}
// 		kp.push_back(c);
// 	}
// 	for(int i=3; i<=sqrt(k); i+=2) {
// 		if(k%i == 0) {
// 			c=1;
// 			while (k%i == 0) {
// 				c *= i;
// 				k /= i;
// 			}
// 			kp.push_back(c);
// 		}
// 	}
// 	if (k>2) kp.push_back(k);
// 	for(int i=0; i<n; i++) {
// 		cin >> x;
// 		for(unsigned int j=0; j<kp.size(); j++) {
// 			if(x % (kp[j]) == 0) {
// 				t /= kp[j];
// 				if(t == 1) {
// 					cout << "Yes" << endl;
// 					return 0;
// 				}
// 				kp[j] = 1;
// 			}
// 		}
// 	}
// 	cout << "No" << endl;
// }