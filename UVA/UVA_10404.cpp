/*
*    target :check whose the winner
*     sol   : just make iteration check if i-k is false then i win in this step
*             like u can't put so u false sure now i'm in (i) win :) 
*
*
*/


#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
bool dp[N];
int arr[15];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m;
	while (scanf("%d %d", &n, &m) == 2) {
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i<m; i++) {
			scanf("%d", arr + i);
		}
		dp[0] = false;
		for (int i = 1; i <= n; i++) {
			dp[i] = false;
			for (int j = 0; j<m; j++) {
				if (i - arr[j] >= 0 && !dp[i-arr[j]]) {
					dp[i] = true;
					break;
				}
			}
		}

		dp[n] == true ? printf("Stan wins\n") : printf("Ollie wins\n");
	}


}

