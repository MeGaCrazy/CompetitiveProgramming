/*
 * @Author: MeGaCrazy
 * @init: 7:52:11 PM Jan 21, 2018
 * @idea:	calculate the time that after that  dragon will catch her then if he reached c sofar so that answer
 *			he's not  Just add+1 and pos = time he take to return begining pos+ f
 *
 *
 * Happy Solving :)
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	//freopen("src/in","r",stdin);
	//freopen("src/out","w",stdout);
#endif

	int vp, vd, t, f, c;
	scanf("%d %d %d %d %d", &vp, &vd, &t, &f, &c);
	if (vp >= vd) {
		printf("0");
		return 0;
	}
	int ans = 0;
	double qpos = vp * t;
	while (qpos + 1e-9 < c) {
		double dt = qpos / (vd - vp);
		qpos += dt * vp;
		//cerr<<qpos<<endl;
		if (qpos + 1e-9 > c) {
			break;
		}
		ans++;
		qpos += (qpos / vd + f) * vp;
	}
	printf("%d", ans);
}
