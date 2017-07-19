/*
*   target : get worst and best nodes
*      sol :worst node that made height at it's maximum  and best it make height as small as possible
*           choose any node and maxmize depth and get the  node of max depth and do the operation twice 
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=5005;
vector<int> adj[N];
int dep[N],n,maxdep,ed;
void dfs(int v,int depth,int pre){
     if(depth>maxdep){maxdep=depth,ed=v;}
     for(int i=0;i<adj[v].size();i++){
           int a=adj[v][i];
           if(pre==a)continue;
           dfs(a,depth+1,v);
           dep[a]=max(dep[a],depth+1);
     }
}

int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
       while(scanf("%d",&n)==1){
           memset(adj,0,sizeof(adj));
           memset(dep,0,sizeof(dep));
           for(int i=1,k;i<=n;i++){
                scanf("%d",&k);
                for(int j=0,a;j<k;j++){
                  scanf("%d",&a);
                  adj[i].push_back(a);
                }                
           }
          maxdep=0;
          dfs(1,0,-1);
          dfs(ed,0,-1);
          dfs(ed,0,-1);
          int minn=1e9;
          vector<int>worst;
          for(int i=1;i<=n;i++){
             if(minn>dep[i]){
               minn=dep[i];
             }
           }
            int mi = 1e9;
            for (int i = 1; i <= n; ++i) mi = min(mi, dep[i]);
            printf("Best Roots  :");
            for (int i = 1; i <= n; ++i) if (dep[i] == mi)printf(" %d", i);
            puts("");
            printf("Worst Roots :");
            for (int i = 1; i <= n; ++i) if (dep[i] == maxdep) printf(" %d", i);
            puts("");
          }
}