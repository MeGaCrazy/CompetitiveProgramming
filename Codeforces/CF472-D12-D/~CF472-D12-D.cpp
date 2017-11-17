/**
*  idea: First Check The Obvious Conditions... and then u should construct the tree How?Um...Shortest edge between two node make that 
*        One is the Parent of another ... and then u want to build with Shortest edge But don't make cycle so i don't want to connect
*        to one  that already connected ... So i will Use DisjointSet and i want to get shorestets edges ,,"That The Main idea of Krushal" :)
*        so do krushal and then check by dfs for every node it's child are have cost as same as krushal :) 
* Compelxity : (n^2log(n))
*
*     Happy Solving :)   
*
**/




#include <bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int> > > edges;
const int  N=2005;
int p[N],sz[N],a[N][N];
int Find(int i){
  return p[i]==i? i : p[i]=Find(p[i]);
}
void Union(int i,int j){
  int x=Find(i),y=Find(j);
  if(x==y)return;
  if(sz[x] >= sz[y])p[y]=x,sz[x]+=sz[y];
  else p[x]=y,sz[y]+=sz[x];
}

vector<pair<int,int > > adj[N];
void dfs(int cur,int pr,int boss,int cost){
//    cerr<<cur<<" " <<pr<<" " << boss<<" " <<cost<<endl;
    if(a[boss][cur]!= cost){
       puts("NO");
       exit(0);
    }
    for(pair<int,int> next : adj[cur]){
       if(next.first != pr){
          dfs(next.first,cur,boss,cost+next.second);
       } 
    }
}
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
     int n;
     scanf("%d",&n);
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",a[i]+j);
             edges.push_back(make_pair(a[i][j],make_pair(i,j)));
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
     sort(edges.begin(),edges.end());
     for( auto node : edges){
        int u=node.second.first;
        int v=node.second.second;
        int cost=node.first;
        if(Find(u)!=Find(v)){
           Union(u,v);
           adj[u].push_back(make_pair(v,cost));
           adj[v].push_back(make_pair(u,cost));
        }
     }
     for(int i=1;i<=n;i++)dfs(i,-1,i,0);
     puts("YES");

}