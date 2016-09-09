#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, m, x, y;

bool contains(vector<int> G, int e) {
	for(int i : G) {
		if(i==e) return true;
	}
	return false;
}
int main() {
	cin >> n >> m;
	vector<vector <int> > G1(n+1);
	vector<vector <int> > G2(n+1);
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		G1[x].push_back(y);
		G1[y].push_back(x);
	}
	for(int i=1;i<=n;i++) {
		for(int j=1; j<=n; j++) {
			if(!contains(G1[i], j)) {
				G2[i].push_back(j);
			}
		}
	}
	if(contains(G1[1],n)) {
		queue<int> q;
		q.push(1);
		int dist[n+1];
		memset(dist, -1, sizeof dist);
		dist[1]=0;
		while(!q.empty()) {
			int u=q.front(); 
			q.pop();
			for(int v : G2[u]) {
				if(dist[v] == -1) {
					dist[v] = dist[u]+1;
					q.push(v);
				}
			}
		}
		cout << dist[n] << endl;
	} else {
		queue<int> q;
		q.push(1);
		int dist[n+1];
		memset(dist, -1, sizeof dist);
		dist[1]=0;
		while(!q.empty()) {
			int u=q.front(); 
			q.pop();
			for(int v : G1[u]) {
				if(dist[v] == -1) {
					dist[v] = dist[u]+1;
					q.push(v);
				}
			}
		}
		cout << dist[n] << endl;
	}
}