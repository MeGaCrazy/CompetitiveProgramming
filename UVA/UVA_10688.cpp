/*
*    Idea : make the interval is the weight of each One Then now it's a classical problem Nested Range Like (Cutting Sticks ) :)
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=505;
int dp[N][N];
int solve(int i,int j){
     if(i>=j)return 0;
     int &ret=dp[i][j];
     if(ret!=-1)return ret;
     ret=(int)2e9;
     for(int k=i;k<=j;k++){
      ret=min(ret,k*(j-i+1)+solve(i,k-1)+solve(k+1,j));
     }
     return ret;
}
int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
        int t,Case=1;
        scanf("%d",&t);
        while(t--){
         memset(dp,-1,sizeof(dp));
         int n,k;
         scanf("%d %d",&n,&k);
         printf("Case %d: %d\n",Case++,solve(k+1,k+n));
        }


}

