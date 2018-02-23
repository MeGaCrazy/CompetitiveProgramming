/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Feb 22 18:29:28 2018
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
const double EPS=1e-4;
struct point {
	double x, y;
	point(double x = 0, double y = 0) :x(x), y(y) {}
	point operator -(point &other) {
		return point(x - other.x, y - other.y);
	}
	bool operator ==(point &other) {
		return fabs(x - other.x) <EPS && fabs(y - other.y) <EPS;
	}
	point operator +(point &other) {
		return point(x + other.x, y + other.y);
	}
	bool operator <(point &other) {
		return x < other.x + EPS || (fabs(x - other.x)<EPS&& y < other.y + EPS);
	}
};
struct circ {
	point cen;
	double r;
};
int dcmp(double x, double y) {
	return fabs(x - y) <EPS ? 0 : x>y ? 1 : -1;
}
double fix_angle(double x) {
	return x < -1 ? -1 : x>1 ? 1 : x;
}
double Get_ang(double a, double b, double c) {
	return acos(fix_angle(((b*b) + (c*c) - (a*a)) / (2 * b*c)));
}
double Angle(point v) {
	return atan2(v.y, v.x);
}
double dot(point v1, point v2) {
	return v1.x*v2.x + v1.y*v2.y;
}
bool isSame(circ p1, circ p2) {
	//     cerr<<p1.cen.x<<" "<<p1.cen.y<<" "<<p2.cen.x<<" "<<p2.cen.y<<endl;
	if (p1.cen == p2.cen&& p1.r >EPS&&dcmp(p1.r, p2.r) == 0)return 1;
}
double length(point v) {
	return sqrt((v.x*v.x) + (v.y*v.y));
}
pair<int, vector<point> > circleInter(circ &pt1, circ &pt2) {
	point c1 = pt1.cen;
	point c2 = pt2.cen;
	double r1 = pt1.r;
	double r2 = pt2.r;
//	if (isSame(pt1, pt2)) {
//		return make_pair(0, vector<point>());
//	}
    if (c1==c2 && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return make_pair(0,vector<point>(3, c1));    // infinity 2 same circles (not points)
    else if (c1==c2 && dcmp(r1,r2)==0 && dcmp(r1,0)==0) { //2 are the same points
        return make_pair(2,vector<point> (1,c1));
    }else if(dcmp(r1,0)==0){ //c1 is a point
        if( dcmp(length(c2-c1),r2)==0)
            return make_pair(2,vector<point>(1,c1));
        return make_pair(0,vector<point>());
    }else if(dcmp(r2,0)==0){ //c2 is a point
        if( dcmp(length(c2-c1),r1)==0)
            return make_pair(2,vector<point>(1,c2));
        return make_pair(0,vector<point>());
    }


	double ang1 = Angle(c2 - c1), ang2 = Get_ang(r2, r1, length(c2 - c1));
	if (isnan(ang2))ang2 = 0;
	point v1 = point(r1*cos(ang1 + ang2), r1*sin(ang1 + ang2));
	vector<point>ret;
	ret.push_back(v1 + c1);
	if (dcmp(dot(ret[0] - c1, ret[0] - c1), r1*r1) != 0 ||
		dcmp(dot(ret[0] - c2, ret[0] - c2), r2*r2) != 0)
		return make_pair(1, vector<point>());
	v1 = point(r1*cos(ang1 - ang2), r1*sin(ang1 - ang2));
	ret.push_back(v1 + c1);
	if (ret[0] == ret[1]) {
		ret.pop_back();
	}
	return make_pair(2, ret);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	circ circ1, circ2;
	while (scanf("%lf %lf %lf", &circ1.cen.x, &circ1.cen.y, &circ1.r) != EOF) {
		scanf("%lf %lf %lf", &circ2.cen.x, &circ2.cen.y, &circ2.r);
		pair<int, vector<point> >ret = circleInter(circ1, circ2);
		if (ret.first == 0) {
			printf("THE CIRCLES ARE THE SAME\n");
		}
		else if (ret.first == 1) {
			printf("NO INTERSECTION\n");
		}
		else {
			sort(ret.second.begin(), ret.second.end());
			for (int i = 0; i<ret.second.size(); i++) {
				printf("(%.3f,%.3f)", ret.second[i].x + EPS, ret.second[i].y + EPS);
			}
			puts("");
		}
	}
}