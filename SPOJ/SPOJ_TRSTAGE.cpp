/*
*   idea : Just make choice take with road and which ticket need [currentNode][mask(ticket avalible]
*
*
*/
#include <bits/stdc++.h>
using namespace std;
int tic,n,m,s,t;
double dp[32][(1<<8)];
int c[10];
const double inf=(int)1e9;
vector<pair<int,int> > adj[32];
double solve(int u,int mask){
     double &ret=dp[u][mask];
     if(ret!=-1){
       return ret;
     }
     if(u==t){
      // cerr<<"reach "<<u<<endl;
       return ret=0.0;
     }
     
     if(mask ==((1<<(tic))-1)){
       return ret=inf; 
     }
     ret=inf;
     for(int i=0;i<(int)adj[u].size();i++){
         int v=adj[u][i].first,dis=adj[u][i].second;
         for(int j=0;j<(int)tic;j++){
            if((mask&(1<<j))==0){
             //  cerr<<u<<" "<<v<<endl;
              ret=min(ret,solve(v,mask|(1<<j))+((double)dis/c[j]));
            }
         }
     }
     return ret;
}


int main(){
      while(scanf("%d %d %d %d %d",&tic,&n,&m,&s,&t),(tic||n||m||s||t)){
          for(int i=0;i<tic;i++){
            scanf("%d",c+i);
          }
          memset(adj,0,sizeof(adj));
          for(int i=0,a,b,dis;i<m;i++){
             scanf("%d %d %d",&a,&b,&dis);
             adj[a].push_back(make_pair(b,dis));
             adj[b].push_back(make_pair(a,dis));
          }
          for(int i=0;i<=n;i++){
             for(int j=0;j<(1<<tic);j++){
                  dp[i][j]=-1;
             }
          }
          double ans=solve(s,0);
          if(ans >= inf){
             puts("Impossible");
          }else{
            printf("%.3f\n",ans);
          }
      }
}