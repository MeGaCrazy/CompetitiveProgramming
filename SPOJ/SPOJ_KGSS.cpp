/*
*      target :get RMQ but for 2 elements not 
*        sol  :Just using the usual RMq but now make segment pair get pair not only 1 :)
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 123456;
typedef pair<int, int>ii;
ii st[N * 4];
int arr[N];
ii join(ii a, ii b) {
	int tmp[5] = {};
	tmp[0] = a.first;
	tmp[1] = a.second;
	tmp[2] = b.first;
	tmp[3] = b.second;
	sort(tmp, tmp + 4);
	return make_pair(tmp[3], tmp[2]);
}
ii build(int p, int l, int r) {
	if (l == r) {
		return st[p] = make_pair(arr[l], 0);
	}
	int mid = (l + r) / 2;
	return st[p] = join(build(2 * p, l, mid), build(2 * p + 1, mid + 1, r));
}
void update(int p, int l, int r, int x, int value) {
	if (l == r&&r == x) {
		st[p].first = value;
		st[p].second = 0;
		arr[l] = value;
		return;
	}
	int mid = (l + r) / 2, t[4];
	if (x <= mid) update(2 * p, l, mid, x, value);
	else update(2 * p+1, mid + 1, r, x, value);
	st[p] = join(st[2 * p], st[2 * p + 1]);
}
ii query(int p, int l, int r, int x, int y) {
	if (x>r || l>y)return make_pair(0, 0);
	if (l >= x&&r <= y) {
		return st[p];
	}
	int mid = (l + r) / 2;
	return join(query(2 * p, l, mid, x, y), query(2 * p + 1, mid + 1, r, x, y));
}
int main() {
	int n, q;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
	}
	build(1, 1, n);

	scanf("%d", &q);
	char s;
	int a, b;
	for (int i = 0; i<q; i++) {
		scanf(" %c %d %d", &s, &a, &b);
		if (s == 'Q') {
			ii ans = query(1, 1, n, a, b);
			printf("%d\n", ans.first + ans.second);
		}
		else {
			update(1, 1, n, a, b);
		}

	}
}
