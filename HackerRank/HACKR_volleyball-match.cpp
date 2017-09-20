/*
*    Idea  : 1- to generate the Sequence for One win in 25 and another less than him Just make States like Pascal Trangle :)
*            2- Now we Go for Conditions 
*                    (a) if n==25 and m<n then it's valid state C[n-1][m] Why not [n] Coz the last Choice he won in it so there is no choice in it
*                    (b) But if The n > 25 and also m That mean the Sequence contiune the min(n,m) Reached how let's explain more further :
*                     if m=27 and m=29   so all sequence can be  0 0 0 -> 0 0 1 and so on u know the 2^n state so every Sequence Before 25
*                     Can have One of This State So The answer is C[24][24] * 2^(min(n,m))
*      
*           Happy Solving :)
*/
#include <bits/stdc++.h>
using namespace std;
const int N=26;
int dp[N][N];
const int MOD=(int)1e9+7;
long long cal(int x){
    if(x==0)return 1;
    if(x==1)return 2;
    long long q=(cal(x/2))%MOD;
    long long ret=(q*q)%MOD;
   return (x&1)?  (ret+ret)%MOD : ret;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if( (n<25&& m<25) || (n>25  && m >25 )&&abs(n-m)!=2||(n==m)||(n==24&&m==25)||(n==25&&m==24)){
       puts("0");
       return 0;
     }
    dp[0][0]=1;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(i) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
        if(j) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
      }
    }
    if(m>n)swap(n,m);
    if(n==25&&m<n){
      printf("%d\n",dp[n-1][m]);
      return 0;
    }
    int ret=dp[24][24];
    int ans=(1ll*ret*cal(min(n,m)-24))%MOD;
    printf("%d\n",ans);
}   