/*
*     Idea : Just make state [Second][people] and Try The Two probablility each time and then get sum of d[t][(i)1..n]*i
*     Happy Solving :)
*/
#include <bits/stdc++.h>
using namespace std;
const int N=2005;
double dp[N][N];



int main(){
   int n,t;
   double p;
   scanf("%d %lf %d",&n,&p,&t);
   memset(dp,0,sizeof(dp));
   dp[0][0]=1;
   for(int i=0;i<t;i++){
     for(int j=0;j<=n;j++){
         if(j==n){
            dp[i+1][j]+=dp[i][j];
           }else{
            dp[i+1][j+1]+=(dp[i][j]*p);
            dp[i+1][j]+=(dp[i][j] * (1-p));
           }
      }
   }
   double ans=0.0;
   for(int i=0;i<=n;i++){
     ans+=(i*dp[t][i]);
   }
   printf("%.8f",ans);
}