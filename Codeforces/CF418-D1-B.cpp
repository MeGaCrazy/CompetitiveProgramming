#include <bits/stdc++.h>
using namespace std;
const int N=105;
int k[N],x[N],prob[N],solver[N];
long long dp[(1<<20)];
bool cmp(int i,int j){
   return k[i] < k[j];
}
int main(){
    int n,m,b;
    scanf("%d %d %d",&n,&m,&b);
    for(int i=1,mm,t;i<=n;i++){
       scanf("%d %d %d",x+i,k+i,&mm);
       while(mm--){
          scanf("%d",&t);
          prob[i]|=(1<<(t-1));
       }
       solver[i]=i;
    }
    sort(solver+1,solver+n+1,cmp);
    long long ans=2e18;
    for(int i=1;i<(1<<m);i++)dp[i]=2e18;
    for(int i=1;i<=n;i++){
       //here idk how to make knapsack :( i will back to solve it later 
        ans=min(ans,1ll*b*k[solver[i]]+dp[(1<<m)-1]);
    }
    if(ans==2e18)puts("-1");
    else printf("%lld\n",ans);
}