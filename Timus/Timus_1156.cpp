/*
*       Just make Bipartite Graph i mean two components
*       check whether it can or not;
*       then chech if can combine some of components together to reach they equal they have same size
*       and combine it that it..
*
*
*/


#include <bits/stdc++.h>
using namespace std;
const int N=12345;
int vis[N];
bool flag;
int num_comp;
int n,m;
vector<int>comp[N][2];
vector<int>adj[N];
int dp[105][105][105];
void dfs(int u,int color){
      if(flag==false)return;
      if(vis[u]!=-1&&vis[u]!=color){
          flag=false;
          return;
      }
      if(vis[u]!=-1)return;
      vis[u]=color;
      comp[num_comp][color-1].push_back(u);
      for(int i=0;i<(int)adj[u].size();i++){
             int v=adj[u][i];
             dfs(v,3-color);
      }
}
int check(int i,int comp1,int comp2){
     if(i==num_comp)return comp1==comp2;
     int &ret=dp[i][comp1][comp2];
     if(ret!=-1)
           return ret;
     ret=check(i+1,comp1+comp[i][0].size(),comp2+comp[i][1].size());
     if(ret==0)
        ret=check(i+1,comp1+comp[i][1].size(),comp2+comp[i][0].size());
     return ret;
}
vector<int>ans1,ans2;
void build(int i,int comp1,int comp2){
         if(i==num_comp)return;
         if(check(i+1,comp1+comp[i][0].size(),comp2+comp[i][1].size())){
             for(int j=0;j<comp[i][0].size();j++){
                int u=comp[i][0][j];
                ans1.push_back(u);
             }
             for(int j=0;j<comp[i][1].size();j++){
                int u=comp[i][1][j];
                ans2.push_back(u);
             }
             build(i+1,comp1+comp[i][0].size(),comp2+comp[i][1].size());
         }else{
         
            for(int j=0;j<comp[i][1].size();j++){
                int u=comp[i][1][j];
                ans1.push_back(u);
             }
             for(int j=0;j<comp[i][0].size();j++){
                int u=comp[i][0][j];
                ans2.push_back(u);
             }
             build(i+1,comp1+comp[i][1].size(),comp2+comp[i][0].size());
         }
}
int main(){
#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
#endif
      int n,m;
      scanf("%d %d",&n,&m);
      n*=2;
      memset(vis,-1,sizeof(vis));
      for(int i=0,a,b;i<m;i++){
          scanf("%d %d",&a,&b);
          adj[a].push_back(b);
          adj[b].push_back(a);
      }
      num_comp=0;
      flag=true;
      for(int i=1;i<=n;i++){
           if(vis[i]==-1)dfs(i,1),num_comp++;
      }
      if(flag==false){
        printf("IMPOSSIBLE\n");
        return 0;
      }
      memset(dp,-1,sizeof(dp));
      if(check(0,0,0)==0){
        printf("IMPOSSIBLE\n");
        return 0;
      }
      build(0,0,0);
      for(int i=0;i<(int)ans1.size();i++){
         printf("%d ",ans1[i]);
      } puts("");
      for(int i=0;i<(int)ans2.size();i++){
         printf("%d ",ans2[i]);
      } puts("");
}