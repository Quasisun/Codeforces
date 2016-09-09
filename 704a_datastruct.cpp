#include <bits/stdc++.h>
#include <iostream>
#include <cstddef>

using namespace std;

int num[300100], cut[300100];
int main() {
	int n,q,s=0, x, y, l=1;
	cin >> n >> q;
	vector<int> notifs;
	for(int i=0; i<q; i++) {
		cin >> x >> y;
		if(x == 1) {
			num[y]++;
			s++;
			notifs.push_back(y);
		} else if (x==2) {
			s -= num[y];
			num[y] = 0;
			cut[y] = notifs.size();
		} else {
			if(y >= l) {
				for(int t=l; t<=y; t++) {
					if(t > cut[notifs[t-1]]) {
						num[notifs[t-1]]--;
						cut[notifs[t-1]] = t;
						s--;
					}
					l=y;
				}
			}
		}
		cout << s << endl;
	}
}
// int main() {
// 	int n, q, x, y;
// 	cin >> n >> q;
// 	struct Node {
// 		int c;
// 		int t;
// 		Node* next;
// 	};

// 	int size=0;
// 	int total=1;
// 	Node* prev;
// 	Node* start = new Node;
// 	start->next = nullptr;

// 	int count[q];
// 	memset(count, 0, sizeof count);
// 	for(int i=0; i<q; i++) {
// 		cin >> x >> y;
// 		if(x == 1) {
// 			prev = start->next;
// 			start->next = new Node;
// 			start->next->c = y;
// 			start->next->t = total;
// 			start->next->next = prev;
// 			size++;
// 			total++;
// 		} else if (x==2) {
// 			Node* iter = start; 
// 			while(iter != nullptr && iter->next != nullptr) {
// 				if(iter->next->c == y) {
// 					iter->next = iter->next->next;
// 					size--;
// 				} else {
// 					iter = iter->next;
// 				}
// 			}
// 		} else {
// 			Node* iter = start; 
// 			while(iter != nullptr && iter->next != nullptr) {
// 				if(iter->next->t <= y) {
// 					iter->next = iter->next->next;
// 					size--;
// 				} else {
// 					iter = iter->next;
// 				}
// 			}
// 		}
// 		count[i] = size;
// 	}
// 	// vector<vector <int> > indices;
// 	// indices.resize(n);
// 	// vector<int> unread;
// 	// int count[q];
// 	// memset(count, 0, sizeof count);

// 	// for(int i=0; i<q; i++) {
// 	// 	cin >> x >> y;
// 	// 	if(x == 1) {
// 	// 		indices[y-1].push_back(unread.size());
// 	// 		unread.push_back(0);
// 	// 	} else if (x==2) {
// 	// 		for(int j=0; j<indices[y-1].size(); j++) {
// 	// 			unread[indices[y-1][j]] = 1;
// 	// 		}
// 	// 	} else {
// 	// 		for(int j=0; j<y; j++) {
// 	// 			unread[j] = 1;
// 	// 		}
// 	// 	}
// 	// 	for(unsigned int j=0; j<unread.size(); j++) {
// 	// 		if (unread[j] == 0) {
// 	// 			count[i]++;
// 	// 		}
// 	// 	}
// 	// }
// 	for(int i=0; i<q; i++) {
// 		cout << count[i] << endl;
// 	}

// }

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long LL;
// int m,n,k,q,i,j,s,t,l=1,r,u,v,x,y,z;
// int A[300008],T[300008],S[300008],L[300008];
// int main(){
// 	scanf("%d%d",&n,&q);
// 	for(i=0;i<q;i++){
// 		scanf("%d%d",&m,&x);
// 		if(m==1)S[++t]=x,A[x]++,s++;
// 		if(m==2)s-=A[x],A[x]=0,T[x]=t;
// 		if(m==3){
// 			for(j=l;j<=x;j++){
// 				if(S[j]==0)continue;
// 				if(j>T[S[j]])A[S[j]]--,s--;
// 				S[j]=0;
// 			}
// 			if(l<x)l=x;
// 		}
// 		printf("%d\n",s);
// 	}
// }