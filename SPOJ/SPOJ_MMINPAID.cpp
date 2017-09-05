/*
*   Idea : Just make check that if node 1 can reach node n and then check;
*          Second make a usual dfs but using mask to check he reach or not :) 
*          
*
*
*/
#include <bits/stdc++.h>
using namespace std;
const int N=11;
int dp[(1<<10)][N];
struct nodes{
 int y;
 int c;
 int p;
 int r;
};
vector<nodes>adj[N];
bool vis[N];
int n;
void check(int i){
      if(vis[i])return;
      vis[i]=1;
  //    cerr<<i<<endl;
      for(int j=0;j<adj[i].size();j++){
         if(vis[adj[i][j].y])continue;
          check(adj[i][j].y);
      }
}
int dfs(int mask,int i){
     int &ret=dp[mask][i];
     if(ret!=-1){
       return ret;
     }
     mask|=(1<<i);
     if(((mask&(1<<1)&&(mask&(1<<n))))){
       return ret=0; 
     }
    // cerr<<" => "<<i<<endl;
     ret=(int)1e9;
     for(int j=0;j<adj[i].size();j++){
//       if((mask&(1<<adj[i][j].y)))continue;
        int a=dfs(mask,adj[i][j].y);
        ret=min(ret,min(a+adj[i][j].r,(mask&(1<<adj[i][j].c))?a+adj[i][j].p:(int)1e9));
     }
     return ret;
}
int main(){
       int m;
       scanf("%d %d",&n,&m);
       for(int i=0;i<m;i++){
           int a,b,c,p,r;
           scanf("%d %d %d %d %d",&a,&b,&c,&p,&r);
           adj[a].push_back(nodes{b,c,p,r});
       } 
       for(int i=0;i<=10;i++)vis[i]=0;
      check(1);
      if(vis[1]==0||vis[n]==0)printf("impossible\n");
      else{
           memset(dp,-1,sizeof(dp));     
           printf("%d",dfs(1,1));
      }
}
