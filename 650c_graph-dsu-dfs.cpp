#include <bits/stdc++.h>
#include <iostream>
//TRICK: Instead of straightup DFS, iterate through ALL the nodes from least to greatest
using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> ii;

int main() {
	int n, m, x;
	cin >> n >> m;
	vector<vector <int> > a;
	for(int i=0; i<n; i++) {
		vector<int> row;
		for(int j=0; j<m; j++) {
			cin >> x;
			row.push_back(x);
		}
		a.push_back(row);
	}

	vector< vector <vector <ii > > > G;
	vector <vector <ii > > dummy(m);
	for(int i=0; i<n; i++) {
		G.push_back(dummy);
	}

	int* parent = new int[m];
	int* indices = new int[m];

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			indices[j] = j;
		}
		sort(indices, indices+m, [a, i](int c, int d){
			return a[i][c] > a[i][d];
		});
		for(int j=0; j<m; j++) {
			if(j == 0) {
				parent[indices[j]] = -1;
			} else if (a[i][indices[j]] == a[i][indices[j-1]]) {
				parent[indices[j]] = parent[indices[j-1]];
			} else {
				parent[indices[j]] = indices[j-1];
			}

		}
		for(int j=0; j<m; j++) {
			if(parent[j] >= 0) {
				G[i][j].push_back(make_pair(i,parent[j]));
			}
		}
	}
	delete[] parent;
	delete[] indices;

	parent = new int[n];
	indices = new int[n];

	for(int j=0; j<m; j++) {
		for(int i=0; i<n; i++) {
			indices[i] = i;
		}
		sort(indices, indices+n, [a, j](int c, int d){
			return a[c][j] > a[d][j];
		});
		for(int i=0; i<n; i++) {
			if(i == 0) {
				parent[indices[i]] = -1;
			} else if (a[j][indices[i]] == a[j][indices[i-1]]) {
				parent[indices[i]] = parent[indices[i-1]];
			} else {
				parent[indices[i]] = indices[i-1];
			}

		}
		for(int i=0; i<n; i++) {
			if(parent[i] >= 0) {
				G[i][j].push_back(make_pair(parent[i],j));
			}
		}
	}

	//dfs
	int dist[n][m];
	memset(dist, 0, sizeof dist);

	stack<ii> s;
	bool root[n][m];
	memset(root, true, sizeof root);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			for(unsigned int k=0; k<G[i][j].size(); k++) {
				root[G[i][j][k].first][G[i][j][k].second] = false;
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(root[i][j]){
				s.push(make_pair(i,j));
				dist[i][j] = 1;
			}
		}
	}

	while(!s.empty()) {
		ii next = s.top(); s.pop();
		vector<ii> neighbors = G[next.first][next.second];
		for(int i=0; i<neighbors.size(); i++) {
			ii neighbor = neighbors[i];
			if(dist[next.first][next.second] + 1 > dist[neighbor.first][neighbor.second]) {
				dist[neighbor.first][neighbor.second] = dist[next.first][next.second] + 1;
				s.push(neighbor);
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(j > 0) cout << " ";
			cout << G[i][j].size();
		}
		cout << endl;
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(j > 0) cout << " ";
			cout << dist[i][j];
		}
		cout << endl;
	}
}
