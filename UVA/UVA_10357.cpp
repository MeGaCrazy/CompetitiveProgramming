/**
 *   @Author : MeGaCrazy
 *   @InitTime : Thu Jan 18 04:12:11 2018
 *   @Idea :  Just Do binary Search to get the least integer make equation zero or negative
 *             speed = dis/time , so just compare the distance between the ball position and
 *              player if < speed * time can caught if not safe
 *   Corner Case : if corrdinate is negative the ball is foul
 *
 *
 *  Happy Solving :)
 **/
#include <bits/stdc++.h>
using namespace std;
const int N = 25;
pair<int, int> arr[N];
int speed[N];
long long dis(int x, int y, int xx, int yy) {
	return (long long) (x - xx) * (x - xx) + (long long) (y - yy) * (y - yy);
}
int main() {
#ifndef ONLINE_JUDGE
	//freopen("src/in", "r", stdin);
	//  freopen("out","w",stdout);
#endif
	int n;
	scanf("PLAYERS=%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[i].first, &arr[i].second, &speed[i]);
	}
	int m;
	scanf("\nBALLS=%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e, f, g;
		scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
		int l = 0, r = 1e9;
		while (r - l > 1) {
			int t = (l + r) >> 1;
			if ((long long) a * ((long long) t * t) + (long long) b * t
					+ (long long) c <= 0)
				r = t;
			else
				l = t;
		}
		int t = r;
		int x = d * t + e;
		int y = f * t + g;
		int found = 0;
		if (x < 0 || y < 0) {
			printf("Ball %d was foul at (%d,%d)\n", i + 1, x, y);
			continue;
		}
		for (int j = 0; j < n; j++) {
			long long D = dis(x, y, arr[j].first, arr[j].second);
			long long S = (long long) speed[j] * speed[j];
			if (D < S * t * t) {
				printf("Ball %d was caught at (%d,%d)\n", i + 1, x, y);
				found = 1;
				break;
			}
		}
		if (!found) {
			printf("Ball %d was safe at (%d,%d)\n", i + 1, x, y);
		}

	}

}
