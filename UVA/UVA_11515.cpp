/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Jan 13 20:14:28 2018
*   @Idea :  Just Make KnapSack With Checking if The the two circle intersect 
*            Only if radius of circle 1 + circle 2 >= the distance between two circle center :)
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
int dis(int x,int y,int xx,int yy){
   return (x-xx)*(x-xx)+(y-yy)*(y-yy);
}
bool valid(int idx,int mask){
      for(int i=0;i<n;i++){
         if(idx==i||(mask & (1<<i))==0)continue;
         int d=dis(a[i].x,a[i].y,a[idx].x,a[idx].y);
      	 if((a[i].l+a[idx].l)*(a[i].l+a[idx].l) >= d)return 0;
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
	if ((mask & (1 << idx)) == 0 && valid(idx,mask))ch1 = solve(idx + 1, mask | (1 << idx)) + a[idx].l * a[idx].l;
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
	printf("%d\n", solve(0,0));
	}
}