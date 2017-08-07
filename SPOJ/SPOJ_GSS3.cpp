#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 50007;
int arr[N];
struct node {
	int maxsum;
	int bothsum;
	int leftsum;
	int rightsum;
};
node st[N * 4];
node join(node left, node right) {
	return node({ 
		max(max(left.maxsum,right.maxsum),left.rightsum + right.leftsum),
		left.bothsum + right.bothsum,
		max(left.maxsum,left.bothsum + right.leftsum)
		,max(right.maxsum,right.bothsum + left.rightsum) });
}
void build(int p, int l, int r) {
	if (l == r) {
		st[p].maxsum = st[p].bothsum = st[p].leftsum = st[p].rightsum = arr[l];
		return;
	}
	else {
		int mid = (l + r) >> 1;
		int np = (p) << 1;
		build(np, l, mid);
		build(np + 1, mid+1, r);
		st[p] = join(st[np], st[np + 1]);
	}
}
void update(int p, int l, int r, int x, int value) {
	if (x>r || l>x)return;
	if (l == r&&x == r) {
		st[p] = { value,value,value,value };
		return;
	}
	int mid = (l + r) >> 1;
	int np = p << 1;
	if (x <= mid)
		update(np, l, mid, x, value);
	update(np + 1, mid + 1, r, x, value);
	st[p] = join(st[np], st[np + 1]);
}
node query(int p, int l, int r, int x, int y) {
	if (l>y || x>r) {
		return node({ (int)-1e9,(int)-1e9,(int)-1e9,(int)-1e9 });
	}
	if (l >= x&&r <= y)return st[p];
	int mid = (l + r) >> 1;
	int np = p << 1;
	node p1 = query(np, l, mid, x, y);
	node p2 = query(np + 1, mid + 1, r, x, y);
	if (p1.bothsum == (int)-1e9)
		return p2;
	if (p2.bothsum == (int)-1e9)
		return p1;
	return join(p1, p2);
}
int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
	}
	build(1, 1, n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int pro, a, b;
		scanf("%d %d %d", &pro, &a, &b);
		if (pro == 0) {
			update(1, 1, n, a, b);
		}
		else {
			printf("%d\n", query(1, 1, n, a, b).maxsum);
		}
	}
}