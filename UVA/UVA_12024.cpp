/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Sep 24 14:58:32 2018
*   @Idea :    Generate first value using dp masks , second using factors.
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N=13;
int dp[1<<N][N];
int fact[N];
int n;
int solve(int mask,int idx){
	if(idx==-1){
	  return 1;
	}
	int &ret=dp[mask][idx];
	if (ret!=-1){
	    return ret;
	}
	ret=0;
	for(int i=0;i<n;i++){
	   if(i!=idx&&((mask>>i)&1)==0){
	      ret+=solve(mask|(1<<i),idx-1);
	   }	
	}
      return ret;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    fact[1]=1;
    memset(dp,-1,sizeof(dp));
    solve(0,N-1);
    for(int i=2;i<N;i++){
       fact[i]=i*fact[i-1];
    }
    while(t--){
    	scanf("%d",&n);    
    	printf("%d/%d\n",solve(0,n-1),fact[n]);
  }

}