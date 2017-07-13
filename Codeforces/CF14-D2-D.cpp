#include <bits/stdc++.h>
using namespace std;
const int N=205;
bool adj[N][N];
int dep[N];
int ans,n;
int dfs(int i,int pre){
     for(int j=1;j<=n;j++){
         if(adj[i][j]&&j!=pre){
              dfs(j,i);
              ans=max(ans,dep[j]+1+dep[i]);
              dep[i]=max(dep[i],dep[j]+1);
         }
     }
    return ans;
}


int main(){
     scanf("%d",&n);
     for(int i=0,a,b;i<n-1;i++){
        scanf("%d %d",&a,&b);
        adj[a][b]=adj[b][a]=1;
     }
     int finalans=0;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
              int a1=0,b1=0;
              if(adj[i][j]){
                 ans=0;memset(dep,0,sizeof(dep));
                  a1=dfs(i,j);
                 ans=0;memset(dep,0,sizeof(dep));
                  b1=dfs(j,i);
              }
               finalans=max(a1*b1,finalans);
         }
        
     }
     printf("%d\n",finalans);
}