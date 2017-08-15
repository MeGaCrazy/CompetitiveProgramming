/*
*     The Nice idea how to add x 
*     look at this (a+x)^2 =a*a +2*a*x+x*x
*     That to solve The big issue :)
*     Second u must have varible type in lazy to know the type of edit 
*     and 2 varbile the orginial value and the square to manage the formula :) 
*/

#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 7;
pair<int,long long> st[N * 4];
pair<int, long long >lazy[N * 4];
int arr[N];
void build(int p, int l, int r) {
	lazy[p] = make_pair(0, 0);
	if (l == r) {
		st[p].first = arr[l];
		st[p].second=arr[l]*arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	int np = (p) << 1;
	build(np, l, mid);
	build(np + 1, mid + 1, r);
	st[p].first = st[np].first + st[np + 1].first;
	st[p].second=st[np].second+st[np+1].second;
}
void pro(int p, int l, int r) {
	int type = lazy[p].first;
	if (lazy[p].first == 0)return;
	if (type == 1){
	   st[p].second +=2*st[p].first*lazy[p].second+(r-l+1)*lazy[p].second*lazy[p].second;
	   st[p].first+=(r-l+1)*lazy[p].second;
	}
	else{ 
	  st[p].second=(r-l+1)*lazy[p].second*lazy[p].second;
	  st[p].first = (r-l+1)*lazy[p].second;
	}
	int np = p << 1;
	if (l != r) {
		if (type == 1) {
			lazy[np].first = 1;
			lazy[np].second += lazy[p].second;
			lazy[np + 1].first = 1;
			lazy[np + 1].second += lazy[p].second;
		}
		else {
			lazy[np + 1].second = lazy[np].second = lazy[p].second;
			lazy[np].first = lazy[np + 1].first = 2;
		}
	}
	lazy[p] = make_pair(0, 0);
}
void update1(int p, int l, int r, int a, int b, int x) {
	if (lazy[p].first != 0)pro(p, l, r);
	if (l>b || a>r)return;
	int np = p << 1;
	if (l >= a&&r <= b) {
                st[p].second+=2*st[p].first*x+(r-l+1)*x*x;
                st[p].first+=(r-l+1)*x;
		if (l != r) {
			lazy[np].second += x;
			lazy[np].first = 1;
			lazy[np + 1].first = 1;
			lazy[np + 1].second += x;
		}
		return;
	}
	int mid = (l + r) >> 1;
	update1(np, l, mid, a, b, x);
	update1(np + 1, mid + 1, r, a, b, x);
	st[p].first = st[np].first + st[np + 1].first;
	st[p].second=st[np].second+st[np+1].second;
}
void update2(int p, int l, int r, int a, int b, int x) {
	if (lazy[p].first != 0)pro(p, l, r);
	if (l>b || a>r)return;
	int np = p << 1;
	if (l >= a&&r <= b) {
		st[p].second = (r-l+1)*x*x;
		st[p].first = (r-l+1)*x;
		if (l != r) {
			lazy[np].second = x;
			lazy[np].first = 2;
			lazy[np + 1].first = 2;
			lazy[np + 1].second = x;
		}
		return;
	}
	int mid = (l + r) >> 1;
	update2(np, l, mid, a, b, x);
	update2(np + 1, mid + 1, r, a, b, x);
	st[p].first = st[np].first + st[np + 1].first;
	st[p].second=st[np].second+st[np+1].second;
}
long long  query(int p, int l, int r, int a, int b) {
	if (lazy[p].first != 0)pro(p, l, r);
	if (l>b || a>r)return 0;
	if (l >= a&&r <= b) {
		return st[p].second;
	}
	int mid = (l + r) >> 1;
	int np = p << 1;
	return query(np, l, mid, a, b) + query(np + 1, mid + 1, r, a, b);

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int t, n, q, Case = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case %d:\n", Case++);
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++) {
			scanf("%d", arr + i);
		}
		build(1, 1, n);
		while (q--) {
			int w, a, b, x;
			scanf("%d %d %d", &w, &a, &b);
			if (w == 2) {
				printf("%lld\n", query(1, 1, n, a, b));
			}
			else if (w == 1) {
				scanf("%d", &x);
				update1(1, 1, n, a, b, x);
			}
			else {
				scanf("%d", &x);
				update2(1, 1, n, a, b, x);
			}
		}
	}
}

