/*
*     Idea : The solution of that problem is the max diameter of Tree of  First path *  max Diameter of Second;
*            when it not Be  intersect if u have edges like that for example :
*                                     1-2 2-3 3-4 
*                                     so if u can take from left node to other node that not interset 
*                                     in other word if i don't use my edge and make my edge like let we say 
*                                     The break of The two tree make that for every edge to get Max diameter for left and right then multiply              
*                                     Happy Solving :)
*/                                                 

#include <bits/stdc++.h>
using namespace std;
const int N=205;
vector<int>adj[N];
vector<pair<int,int> >edges;
pair<int,int>cur_edge;
int ans;
int mxdp;
int v;
void dfs(int u,int p,int depth){
       if(depth>mxdp){
          mxdp=depth;
          v=u;
       }
       for(int i=0;i<(int)adj[u].size();i++){
          if(adj[u][i]!=p&&(cur_edge!=make_pair(adj[u][i],u))&&(cur_edge!=make_pair(u,adj[u][i]))){
             dfs(adj[u][i],u,depth+1);
          }
       }
}
int solve(int u){
	
        mxdp=-1;
        dfs(u,-1,0);
        mxdp=-1;
        dfs(v,-1,0);
        return mxdp;
}
int main(){
  
       int n;
       scanf("%d",&n);
       for(int i=0,a,b;i<n-1;i++){
         scanf("%d %d",&a,&b);
         adj[a].push_back(b);
         adj[b].push_back(a);
         edges.push_back(make_pair(a,b));
       }
       for(int i=0;i<n-1;i++){
           cur_edge=edges[i];
           int dep1=solve(edges[i].first);
           int dep2=solve(edges[i].second);
           ans=max(ans,dep1*dep2);
       }
       printf("%d",ans);
       
 }   