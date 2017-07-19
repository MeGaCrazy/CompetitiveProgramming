/*
*  target : count ways to make valid coloring for brackets 
*   sol   : 1- assign every close bracket with it's correspond open bracket
*           2- Just all choice we have is [0,1],[1,0],[0,2],[2,0] for any pair
*           3- Just the state for dp is (StartOfInterval,ENdOfInterval,LeftBracketColor,RigthBracketColor)
*           4- Just make the choices we knew above... 
*           Condition : 1-Must not two neighbour have the sama color
*                   
*
*
*
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 705;
int L[N], R[N], dp[N][N][3][3];
char str[N];
const int rem = ((int)1e9) + 7;
int solve(int st, int en, int l, int r) {
	if (st>en) {
		return 1;
	}
	int &ret = dp[st][en][l][r];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 1; i<3; i++) {
		if (R[st]<en || i != r)
			ret = ((ret)+(long long)solve(st + 1, R[st] - 1, 0, i)*solve(R[st] + 1, en, i, r)) % rem;
		if (l != i) {
			ret = ((ret)+(long long)solve(st + 1, R[st] - 1, i, 0)*solve(R[st] + 1, en, 0, r)) % rem;
		}
	}
	return ret;
}
int main() {
	scanf("%s", str);
	int sz = strlen(str);
	int cnt = 0;
	for (int i = 0; i<sz; i++) {
		if (str[i] == '(') {
			L[cnt++] = i;
		}
		else {
			R[L[--cnt]] = i;
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, sz - 1, 0, 0));
}