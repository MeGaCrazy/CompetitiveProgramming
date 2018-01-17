/*
 *
 * @Author : MeGaCrazy
 * @init : 8:21:39 PM Jan 17, 2018
 * @idea :  simulate the process using dp states that [previous_choice][value so far]
 *          and try to get choice from 1 to Min(1,2*previous_choice) if return 0 then i win because the second play is the opponent
 *
 * Happy Solving :)
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
bool first;
int solve(int prev, int rem) {
	//cerr << prev << " " << rem << endl;
	if (rem == 0) {
		return 0;
	}
	int &ret = dp[prev][rem];
	if (ret != -1) {
		return ret;
	}
	if (first == 1) {
		first = 0;
		for (int i = 1; i <= N; i++) {
			if (rem - i <= 0)
				break;
			if (solve(i, rem - i) == 0)
				return ret = 1;
		}

	} else {
		for (int i = 1; i <= min(N, prev * 2); i++) {
			if (rem - i == 0)
				return ret = 1;
			if (rem - i < 0)
				return ret = 0;
			if (solve(i, rem - i) == 0)
				return ret = 1;
		}

	}
	return ret = 0;
}
int main() {
#ifndef ONLINE_JUDGE
	//freopen("in", "r", stdin);
#endif
	int n;
	while (scanf("%d", &n), n) {
		memset(dp, -1, sizeof(dp));
		first = 1;
		bool ret = solve(0, n);
		printf(ret == 1 ? "Alicia\n" : "Roberto\n");
	}

}
