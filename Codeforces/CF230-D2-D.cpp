#include <bits/stdc++.h>
using namespace std;
const int N=123456;
vector<pair<int,int> >adj[N];
set<int>p[N];
int dis[N];
int n,m;
int bfs(int s){
       dis[s]=0;
       priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >pq;
       pq.push(make_pair(dis[s],s));
       while(!pq.empty()){
           int u=pq.top().second;
           int u_cost=pq.top().first;
           pq.pop();
           if(dis[u]<u_cost)continue;
           while(p[u].count(u_cost))u_cost++;
           for(int i=0;i<(int)adj[u].size();i++){
             int v=adj[u][i].second;
             int v_cost=adj[u][i].first;
             if(dis[v]>(u_cost+v_cost)){
               dis[v]=(u_cost+v_cost);
               pq.push(make_pair(dis[v],v));
             }
           }
       }

  return dis[n]==(int)2e9?-1:dis[n];
}



int main(){
     
      scanf("%d %d",&n,&m);
      for(int i=1,a,b,w;i<=m;i++){
          scanf("%d %d %d",&a,&b,&w);
          adj[a].push_back(make_pair(w,b));
          adj[b].push_back(make_pair(w,a));
      }
      for(int i=1,a,k;i<=n;i++){
          scanf("%d",&k);
          while(k--){
            scanf("%d",&a);
            p[i].insert(a);
          }
          dis[i]=(int)2e9;
      }
      printf("%d\n",bfs(1)); 

      for(int i=1;i<=n;i++){
        cerr<<dis[i]<<endl;
      }

}