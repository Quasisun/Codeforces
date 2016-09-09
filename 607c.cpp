#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// const int N = 2000010;

// char a[N], b[N], s[N];
// int p[N];

// int main() {
//   int n;
//   scanf("%d", &n);
//   n--;
//   scanf("%s", a);
//   scanf("%s", b);
//   for (int i = 0; i < n - i - 1; i++) {
//     swap(a[i], a[n - i - 1]);
//   }
//   for (int i = 0; i < n; i++) {
//     if (a[i] == 'N') a[i] = 'S'; else
//     if (a[i] == 'E') a[i] = 'W'; else
//     if (a[i] == 'S') a[i] = 'N'; else
//     if (a[i] == 'W') a[i] = 'E';
//   }
//   for (int i = 0; i < n; i++) {
//     a[n + i] = b[i];
//   }
//   int len = n + n;
//   for (int i = 0; i < len; i++) {
//     s[i + 1] = a[i];
//   }
//   int k = 0;
//   p[1] = 0;
//   for (int i = 2; i <= len; i++) {
//     while (k > 0 && s[i] != s[k + 1]) {
//       k = p[k];
//     }
//     if (s[i] == s[k + 1]) {
//       k++;
//     }
//     p[i] = k;
//   }
//   for(int i=0; i<=len; i++) {
//   	cout << p[i] << " ";
//   }
//   cout << endl;
//   int z = p[len];
//   while (z > n) {
//     z = p[z];
//   }
//   puts(z > 0 ? "NO" : "YES");
//   return 0;
// }
#define INF 2000000000
typedef pair<char,int> ci;

int n;
string s1, s2;
ci l1[1000010], l2[1000010];
char opp(char c) {
	if(c == 'N') return 'S';
	if(c == 'S') return 'N';
	if(c == 'W') return 'E';
	return 'W';
}

bool one(int z) {
	for(int i=0; i<z; i++) {
		if(l1[i].first != opp(l2[z-i].first) || l1[i].second != l2[z-i].second) {
			return false;
		}
	}
	if(l1[z].first != opp(l2[0].first)) return false;
	return true;
}

bool two(int z) {
	for(int i=0; i<z; i++) {
		if(l2[i].first != opp(l1[z-i].first) || l2[i].second != l1[z-i].second) {
			return false;
		}
	}
	if(l2[z].first != opp(l1[0].first)) return false;
	return true;
}

int main() {
	cin >> n >> s1 >> s2;
	int i=s1.length()-1, j=0, count;
	char nxt;
	while(i>=0) {
		nxt = s1[i];
		count=0;
		while(s1[i] == nxt) {
			count++;
			i--;
		}
		l1[j] = ci(nxt,count);
		j++;
	}
	i=s2.length()-1;
	int k=0;
	while(i>=0) {
		nxt = s2[i];
		count=0;
		while(s2[i] == nxt) {
			count++;
			i--;
		}
		l2[k] = ci(nxt,count);
		k++;
	}
	// for(int q=0; q<n; q++) {
	// 	cout << l1[q].first << " " << l1[q].second << endl;
	// }
	// for(int q=0; q<n; q++) {
	// 	cout << l2[q].first << " " << l2[q].second << endl;
	// }
	for(int z=0; z<min(j,k); z++) {
		if(one(z) || two(z)) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}