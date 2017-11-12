/*
*   Idea : The problem Depend on Josephus Problem 
*          well explained in this link https://www.youtube.com/watch?v=uCsD3ZGzMgE
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=30005;
int win[N];
int main(){
#ifndef  ONLINE_JUDGE
       //  freopen("in","r",stdin);
#endif
       for(int i=2;i<=N;i*=2){
           int cur=1;
           for(int j=i;j<=N&&j<i*2;j++){
                 win[j]=cur;
                 cur+=2;
           }
       }
       int n,Cas=1;
       int t;
       scanf("%d",&t);
       while(t--){
          scanf("%d",&n);
          int ans=0;
          while(win[n]!=n){
             ans++;
             n=win[n];
          }
          printf("Case %d: %d %d\n",Cas++,ans,n);
       }
}


