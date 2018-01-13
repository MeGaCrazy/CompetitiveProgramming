/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Jan 13 20:14:28 2018
*   @Idea :
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct crane {
	int x, y, l;
};
const int N = 16;
crane a[N];
int dp[N][1 << N];
int n;
pair<int, int>point[N];
pair<int, int>curpoint[N];
int xx[] = { -1,-1,1,1 };
int yy[] = { -1,1,1,-1 };
int cross(pair<int, int> o, pair<int, int> a, pair<int, int> b) {
	return (int)(a.first - o.first)*(b.second - o.second) - (a.second - o.second)*(b.first - o.first);
}

bool check(int i, int j) {
       if(PointOn(a[i],a[j].s)||PointOn(a[i],a[j].e)||PointOn(a[j],a[i].s)||PointOn(a[j],a[i].e)){
             return 1;
         }
	if (cross(point[i], point[i + 1], curpoint[j])*cross(point[i], point[i + 1], curpoint[j + 1])<0 &&
		cross(point[i + 1], point[i], curpoint[j])*cross(point[i + 1], point[i], curpoint[j + 1])<0 &&
		cross(curpoint[j], curpoint[j + 1], point[i])*cross(curpoint[j], curpoint[j + 1], point[i + 1])<0 &&
		cross(curpoint[j + 1], curpoint[j], point[i])*cross(curpoint[j + 1], curpoint[j], point[i + 1])<0
		) return 1;
	return 0;
}
int valid(int idx) {
	int len = 0;
	for (int j = 0; j<4; j += 2) {
		int L = a[idx].l;
		curpoint[len++] = make_pair(a[idx].x + L*xx[j], a[idx].y + L*yy[j]);
	}
	for (int j = 1; j<4; j += 2) {
		int L = a[idx].l;
		curpoint[len++] = make_pair(a[idx].x + L*xx[j], a[idx].y + L*yy[j]);
	}
	for (int i = 0; i<n; i++) {
		if (i == idx)continue;
		int L = a[i].l;
		int X = a[i].x;
		int Y = a[i].y;
		for (int j = 0; j<4; j++) {
			point[j] = make_pair(X + L*xx[j], Y + L*yy[j]);
		}
	}
	for (int i = 0; i<4; i += 2) {
		for (int j = 0; j<4; j += 2) {
			if (check(i, j))return 0;
		}
	}
	return 1;
}
int solve(int idx, int mask) {
	if (idx==n)
		return  0;
	int &ret = dp[idx][mask];
	if (ret != -1)
		return  ret;
	int ch1 = 0;
	if ((mask & (1 << idx)) == 0 && valid(idx))ch1 = solve(idx + 1, mask | (1 << idx)) + a[idx].l * a[idx].l;
	ret = max(ch1, solve(idx + 1, mask));
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	//   freopen("out","w",stdout);
#endif
	int t;
	scanf("%d", &t);
	while(t--){
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].l);
	}
	memset(dp, -1, sizeof(dp));
	double pi = acos(-1);
//	int f=(int)((double)solve(0,0) / pi);
	printf("%d\n", solve(0,0));
	}
}