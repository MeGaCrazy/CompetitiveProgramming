/*
 * @Author: MeGaCrazy
 * @init: 8:12:59 PM Jan 18, 2018
 * @idea:
 *
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
	int r1, r2, c1, c2, d1, d2;
	scanf("%d %d %d %d %d %d", &r1, &r2, &c1, &c2, &d1, &d2);
	bool f = 0;
	for (int x = 1; x <= 9; x++) {
		for (int xx = 1; xx <= 9; xx++) {
			if (x == xx)
				continue;
			for (int y = 1; y <= 9; y++) {
				if (y == x || y == xx)
					continue;
				for (int yy = 1; yy <= 9; yy++) {
					if (x == yy || xx == yy || y == yy)
						continue;
					if (d1 == x + yy && d2 == xx + y && c1 == x + xx
							&& c2 == y + yy && r1 == x + y && r2 == xx + yy) {
						printf("%d %d\n%d %d", x, y, xx, yy);
						f = 1;
						break;
					}
				}
			}
		}
	}
	if (!f)
		puts("-1");

}
