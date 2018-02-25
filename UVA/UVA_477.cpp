/**
*   @Author : MeGaCrazy
*   @InitTime : Sun Feb 25 11:28:57 2018
*   @Idea :  Just Check if the point inside circle if circle equation < r*r =D 
*            For rectangle Check if the point for each side are in counter clockwise
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const double ff = 9999.9, EPS = 1e-5;
struct point {
	double x, y;
	point(double x = 0, double y = 0) :x(x), y(y) {}
	point operator -(point &other) {
		return point(x - other.x, y - other.y);
	}
};
struct circ {
	point cen;
	double r;
	circ(point cen=point(1,2), double r=0) :cen(cen), r(r) {}
};
struct seg {
	point pt[4];
	seg(point a = point(), point b = point(), point c = point(), point d = point()):pt({a,b,c,d}){}
};

struct both {
	seg s;
	circ c;
	char ch;
	both(char ch, point &a, point &b, point &c, point &d) :s(a, b, c, d), ch(ch) {}
	both(char ch, point cen, double r) :c(cen, r), ch(ch) {}
};
double cross(point &v1, point &v2) {
	return v1.x*v2.y - v1.y*v2.x;
}
double norm(point &v) {
	return sqrt((v.x*v.x) + (v.y*v.y));
}
int ccw(point &a, point &b, point &c) {
	point v1 = b - a;
	point v2 = c - a;
	if (cross(v1, v2) >EPS)return 1;
	if (cross(v1, v2) < -EPS)return -1;
	if (v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
	if (norm(v1) < norm(v2) - EPS)return  1;
	return  0;
}
bool containSeg(seg &s, point &cur) {
	for (int i = 0; i<4; i++) {
		if (ccw(s.pt[i], s.pt[(i + 1) % 4], cur) <= 0)return 0;
	}
	return 1;
}
bool containCir(point &cen, double r, point &cur) {
	return (cur.x - cen.x)*(cur.x - cen.x) + (cur.y - cen.y)*(cur.y - cen.y)<r*r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	//freopen("out","w",stdout);
#endif
	char ch;
	vector<both>arr;
	while (scanf(" %c", &ch), ch != '*') {
		if (ch == 'r') {
			point c, b;
			scanf("%lf %lf %lf %lf", &c.x, &c.y, &b.x, &b.y);
			point a = point(c.x, b.y);
			point d = point(b.x, c.y);
			arr.push_back(both(ch, a, b, d, c));
		}
		else {
			point cen;
			double r;
			scanf("%lf %lf %lf", &cen.x, &cen.y, &r);
			arr.push_back(both(ch, cen, r));
		}
	}
	point pt;
	int cnt = 0;
	while (scanf("%lf %lf", &pt.x, &pt.y)) {
		if (fabs(pt.x - ff)<EPS && fabs(pt.y - ff)<EPS)break;
		cnt++;
		bool f = 0;
		for (int i = 0; i<(int)arr.size(); i++) {
			both cur = arr[i];
			if (cur.ch == 'r'&&containSeg(cur.s, pt)) {
			   	printf("Point %d is contained in figure %d\n", cnt, i + 1);
				f = 1;
			}
			else if (cur.ch == 'c'&&containCir(cur.c.cen, cur.c.r, pt)) {
				printf("Point %d is contained in figure %d\n", cnt, i + 1);
				f = 1;
			}
		}
		if (!f) {
			printf("Point %d is not contained in any figure\n", cnt);
		}
	}

}