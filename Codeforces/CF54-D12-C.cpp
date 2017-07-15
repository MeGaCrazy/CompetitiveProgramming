/*
*     target : calculate the probability for those numbers has digit begin with 1 in some ranges
*      sol   : 1- Think for ranges contain 1 like [1,1],[10,19],[100,199] and so one now u get the pattern :) 
*              2- get count all numbers with 1 by trick above :) and just use the givin to calcuate the probability for numbers 1..n
*              3- then do usual dp probability 2 choice success or failed :) and then check all probability from n if > n*k that the answer
* 
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1005;
long double prob[N];
long double dp[N][N];
long long  L[N],R[N];

int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       cin>>L[i]>>R[i];
    }
    scanf("%d",&k);

    for(int i=1;i<=n;i++){
       long double ratio=0;
       long long fac=1;
       for(int j=0;j<=18;fac*=10,j++){
         ratio+=max(min(R[i],2*fac-1)-max(L[i],fac)+1,0ll);
       }
       prob[i]=(long double)(1.0)*(ratio)/(R[i]-L[i]+1);
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1.0;
    for(int i=1;i<=n;i++){
       for(int j=0;j<=i;j++){
            if(j==0){
              dp[i][j]=dp[i-1][j]*(1-prob[i]);
            }else{
              dp[i][j]=dp[i-1][j-1]*(prob[i])+((long double)1.0-prob[i])*(dp[i-1][j]);
            }
        }
    }
    long double ans=0.0;
    for(int i=0;i<=n;i++){
       if(i*100>=(k*n)){
        ans+=dp[n][i];
       }
    }
    cout<<setprecision(15)<<ans<<endl;
}