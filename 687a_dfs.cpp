#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

#define INF 2000000000000000000ll

int n,m,x,y,u, nxt;
int par[100010];
vector<vector <int> > G(100010);

int main() {
	memset(par, -1, sizeof par);
	
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int nxt = 1; nxt<=n; nxt++) {
		if(par[nxt] != -1) continue;
		stack<int> s;
		s.push(nxt);
		par[nxt] = 0;
		while(!s.empty()) {
			u = s.top();
			s.pop();
			for(int v : G[u]) {
				if (par[v] == -1) {
					par[v] = (par[u] + 1) % 2;
					s.push(v);
				} else if (par[v] != (par[u] + 1) % 2) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	for(int p = 0; p < 2; p++) {
		int count = 0;
		int first = -1;
		for(int i=1; i<=n; i++) {
			if(par[i] == p) {
				if(first == -1) first = i;
				count++;
			}
		}
		cout << count << endl;
		for(int i=1; i<=n; i++) {
			if(par[i] == p) {
				if(i != first) cout << " ";
				cout << i;
			}
		}
		cout << endl;
	}
}