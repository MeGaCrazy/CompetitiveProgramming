/*
 *    Just using dp choose element and go to two intervals :) 
 * 
 *
 *
*/

#include <bits/stdc++.h>
using namespace std;
const int N=55;
int dp[N][N],arr[N],n;
int solve(int l,int r){
      if(l+1==r)return 0;
      int &ret=dp[l][r];
      if(ret!=-1)return ret;
      ret=(int)1e9;
      for(int cur=l+1;cur<r;cur++){
         ret=min(ret,(arr[r]-arr[l])+solve(l,cur)+solve(cur,r));
      }
      return  ret;
}
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
       int length;
      while(scanf("%d",&length),length){
           scanf("%d",&n);
           for(int i=1;i<=n;i++){
              scanf("%d",arr+i);
           }
           arr[0]=0,arr[n+1]=length;
           memset(dp,-1,sizeof(dp));
           printf("The minimum cutting is %d.\n",solve(0,n+1));
      }

}