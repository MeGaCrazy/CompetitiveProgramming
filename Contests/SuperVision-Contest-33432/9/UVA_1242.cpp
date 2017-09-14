/*
*  Idea : From Observation all he need that there is two disjoint path between each other if there is Print yes otherwise no 
*         Summary : using maxflow to check if there is two disjoint path :)
*         MyCodeRunTime : 1.117 sec    
*
*         Happy Solving :)
*/
#include <bits/stdc++.h>
using namespace std;
const int N=10005;
vector<int>adj[N];
bool vis[N];
int cap[N][N];
int p[N];
int f;
int s,t;
void mxflow(int v,int minedge){
    if(v==s){ f=minedge;return;}
    else if(p[v]!=-1){
       mxflow(p[v],min(minedge,cap[p[v]][v]));
       cap[v][p[v]]+=f,cap[p[v]][v]-=f;
    }
}

int main(){
#ifndef ONLINE_JUDGE
      //  freopen("in","r",stdin);
//        freopen("out","w",stdout);
#endif
        int n,m,Case=1;
        while(scanf("%d %d",&n,&m),(n||m)){
            printf("Case %d: ",Case++);
            memset(cap,0,sizeof(cap));
            memset(adj,0,sizeof(adj));
             for(int i=0,a,b;i<m;i++){
               scanf("%d %d",&a,&b);
               adj[a].push_back(b);
               adj[b].push_back(a);
               cap[a][b]++,cap[b][a]++;
             }
             scanf("%d %d",&s,&t);
             int ans=0;
             int l=2;
             while(l--){
               memset(vis,0,sizeof(vis));
               memset(p,-1,sizeof(p));
               queue<int>q;
               q.push(s);
               vis[s]=1;
               while(!q.empty()){
                   int u=q.front();
                   q.pop();
                   if(u==t)break;
                   for(int i=0;i<(int)adj[u].size();i++){
                      int v=adj[u][i];
                      if(vis[v]||cap[u][v]<=0)continue;
                      q.push(v);
                      p[v]=u;
                      vis[v]=1;
               }
             }
            mxflow(t,(int)1e8);
            if(f)ans++;
            f=0;
           }
           if(ans==2)puts("YES");else puts("NO");
        }
}



