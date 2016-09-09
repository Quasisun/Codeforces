#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int l,r,x[610000],n,K;
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	long long num=0;
	for (int i=1;i<=n;i++) num+=x[i];
	int l=1,r=1e9+1,ansl=1;
	while (l<r){
		int mid=l+r>>1;
		long long tot=0;
		for (int i=1;i<=n;i++)
			if (mid>=x[i]) tot+=mid-x[i];
		if (tot>K) r=mid;
		else {
			l=mid+1; ansl=mid;
		}
	}
	l=ansl,r=1e9+1; int ansr=r;
	while (l<r){
		int mid=l+r>>1;
		long long tot=0;
		for (int i=1;i<=n;i++)
			if (mid<=x[i]) tot+=x[i]-mid;
		if (tot>K) l=mid+1;
		else {
			r=mid; ansr=mid;
		}
	}
	if (ansl==ansr&&num%n) ansr++;
	printf("%d\n",ansr-ansl);
	return 0;
}

// using namespace std;
// typedef long long ll;

// ll n, k, lo, hi, mid, sum1, sum2, ans1, ans2;
// int c[500010];

// int main() {
// 	cin >> n >> k;
// 	for(int i=0; i<n; i++) {
// 		cin >> c[i];
// 	}
// 	sort(c, c+n);
// 	// lo = c[0]-1;
// 	// hi = c[n-1]+1;
// 	// while(lo < hi-1) {

// 	// 	mid = lo + (hi-lo)/2;
// 	// 	sum1 = 0;
// 	// 	sum2 = 0;
// 	// 	for(int i=0; i<n; i++) {
// 	// 		if(c[i] <= mid) {
// 	// 			sum1 += mid - c[i];
// 	// 		} else {
// 	// 			sum2 += c[i] - mid;
// 	// 		}
// 	// 	}
// 	// 	//cout << sum1 << " " << sum2 << endl;
// 	// 	if (sum1 == sum2) {
// 	// 		if(k >= sum1) {
// 	// 			cout << 0 << endl;
// 	// 			return 0;
// 	// 		}
// 	// 		lo = mid;
// 	// 	} else if (sum1 < sum2) {
// 	// 		lo = mid;
// 	// 	} else {
// 	// 		hi = mid;
// 	// 	}
// 	// }

// 	// sum1 = 0;
// 	// sum2 = 0;
// 	// for(int i=0; i<n; i++) {
// 	// 	if(c[i] <= lo) {
// 	// 		sum1 += lo - c[i];
// 	// 	} else {
// 	// 		sum2 += c[i] - hi;
// 	// 	}
// 	// }
// 	// if (k >= max(sum1, sum2)) {
// 	// 	cout << 1 << endl;
// 	// 	return 0;
// 	// }


// 	//cout << "hi" << endl;

// 	lo=c[0]-1;
// 	hi=c[n-1]+1;
// 	while(lo < hi-1) {
// 		mid = lo + (hi-lo)/2;
// 		sum1 = 0;
// 		for(int i=0; i<n; i++) {
// 			if(c[i] < mid) {
// 				sum1 += mid - c[i];
// 			} else {
// 				break;
// 			}
// 		}
// 		if(sum1 <= k) {
// 			lo = mid;
// 		} else {
// 			hi = mid;
// 		}
// 	}
// 	ans1 = lo;

// 	lo=c[0]-1;
// 	hi=c[n-1]+1;
// 	while(lo < hi-1) {
// 		mid = lo + (hi-lo)/2;
// 		sum2 = 0;
// 		for(int i=n-1; i>=0; i--) {
// 			if(c[i] > mid) {
// 				sum2 += c[i] - mid;
// 			} else {
// 				break;
// 			}
// 		}
// 		if(sum2 <= k) {
// 			hi = mid;
// 		} else {
// 			lo = mid;
// 		}
// 	}
// 	ans2 = hi;

// 	if(ans1 - ans2 >= -1) {
// 		cout << (accumulate(c, c+n, 0ll) % n > 0) << endl;
// 		return 0;
// 	}
// 	cout << ans2 - ans1 << endl;
// }