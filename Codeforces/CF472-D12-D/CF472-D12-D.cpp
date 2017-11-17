/**
*   Idea : we first check the non valid obvious condition and then we Go For Good Check
*          How we know that u is the child of v ? .... v's shortest edge is let to u :) from that if you try to reach any node x from u or v
*          u will observe that distance[v][x] - distance[u][x] = distance[v][x] coz the only difference in 1 weight is the edge between them :) 
* Complexity : (n^2);
*
*          Happy Solving :)
**/

#include <bits/stdc++.h>
using namespace std;

const int N=2006;
int a[N][N],leaf[N];

int main(){
#ifndef ONLINE_JUDGE
      freopen("in","r",stdin);
#endif
     int n;
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
        long long best=2e18;
        for(int j=1;j<=n;j++){
            scanf("%d",a[i]+j);
            if(i!=j&&best  > a[i][j])leaf[i]=j,best=a[i][j];
        }
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((a[i][j]==0)^(i==j)){
              return puts("NO"),0;
            }
            if(a[i][j]!=a[j][i]){
               return puts("NO"),0;
            }
        }
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
           if( abs(a[i][j] - a[leaf[i]][j])!=a[i][leaf[i]]){
             return puts("NO"),0;
           }
        }
     }
     puts("YES");
}
