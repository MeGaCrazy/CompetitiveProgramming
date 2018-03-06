/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Mar 06 20:05:12 2018
*   @Idea :   Just Check if polygon are interset or one contain another :) 
*             and two know connected groups fastly  use DSU
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;


struct point {
	int x, y;
	point(int x = 0, int y = 0) :x(x), y(y) {}
	point operator -(point &other) {
		return point(x - other.x, y - other.y);
	}
	bool operator ==(point &other) {
		return x == other.x&&y == other.y;
	}

};


const int N = 45;
int sz[N], p[N];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		p[i] = i;
		sz[i] = 1;
	}
}
int Find(int i) {
	return p[i] == i ? i : p[i] = Find(p[i]);
}
bool isSame(int i, int j) {
	return Find(i) == Find(j);
}

void Join(int i, int j) {
	int x = Find(i), y = Find(j);
	if (sz[x] >= sz[y]) {
		sz[x] += sz[y];
		p[y] = x;
		sz[y] = 0;
	}
	else {
		sz[y] += sz[x];
		sz[x] = 0;
		p[x] = y;
	}
}



long long norm(point &v1) {
	return 1ll * v1.x*v1.x + 1ll * v1.y*v1.y;
}
long long cross(point &v1, point &v2) {
	return 1ll * v1.x*v2.y - 1ll * v1.y*v2.x;
}
int ccw(point &a, point &b, point &c) {
	point v1 = b - a;
	point v2 = c - a;
	if (cross(v1, v2) >0)return 1;
	if (cross(v1, v2) <0)return -1;
	if (v1.x*v2.x <0 || v1.y *v2.y <0)return -1;
	if (norm(v1) < norm(v2))return 1;
	return 0;
}

bool InterSeg(point &a, point &b, point &c, point &d) {
	bool f1 = (b == a), f2 = (c == d);
	if (f1&&f2) return c == a;
	if (f1)return ccw(c, d, a) == 0;
	if (f2)return ccw(a, b, c) == 0;

	return ccw(a, b, c)*ccw(a, b, d) <= 0 &&
		ccw(c, d, a)*ccw(c, d, b) <= 0;
}
bool onpoly(vector<point>&v, point &pt) {
	int cnt = 0;
	int n = (int)v.size();
	for (int i = 0, j = n - 1; i<n; j = i++) {
		point &cur = v[j];
		point &nxt = v[i];
		point v1 = nxt - cur;
		point v2 = pt - cur;
	
		if (ccw(cur, nxt, pt) == 0)return 1;
		if (cur.y <= pt.y) {
			if (nxt.y > pt.y && cross(v1, v2) >0) cnt++;
		}
		else {
			if (nxt.y <= pt.y && cross(v1, v2) <0) cnt--;
		}
	}
	
	return cnt != 0;
}
bool Inter(vector<point>&a, vector<point>&b) {


	int n = (int)a.size();
	int m = (int)b.size();
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (InterSeg(a[i], a[(i + 1) % n], b[j], b[(j + 1) % m]))return 1;
		}
	}
	for (int i = 0; i<m; i++) {
		if (onpoly(a, b[i]))return 1;

	}
	for (int i = 0; i<n; i++) {
		if (onpoly(b, a[i]))return 1;

	}

	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	//freopen("out","w",stdout);
#endif
	int n;
	while (scanf("%d", &n), n) {
		cin.ignore();
		string s;
		init(n);
		vector<vector<point> >v;
		for (int i = 0; i<n; i++) {
			getline(cin, s);
			stringstream in(s);
			int x, y;
			vector<point>tmp;
			while (in >> x >> y) {
				tmp.push_back(point(x, y));

			}
			v.push_back(tmp);
		}

		for (int i = 0; i<n; i++) {
			for (int j = i + 1; j<n; j++) {
				if (Inter(v[i], v[j]) && !isSame(i, j)) {
					Join(i, j);

				}
			}
		}
		int ans = 0;
		for (int i = 0; i<n; i++) {
			if (sz[i])ans++;
		}
		printf("%d\n", ans);

	}



}