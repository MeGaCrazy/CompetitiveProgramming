/*
*   Just make dijkstra then count how many vertex his distance is l and then check if can be in road :) 
*
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=(int)1e5+7;
int x[N],y[N],w[N],dis[N];
vector<pair<int,int> >adj[N];

int main(){
   int n,m,s;
   scanf("%d %d %d",&n,&m,&s);
   for(int i=1;i<=m;i++){
      scanf("%d %d %d",x+i,y+i,w+i);
      adj[x[i]].push_back(make_pair(w[i],y[i]));
      adj[y[i]].push_back(make_pair(w[i],x[i]));
   }
   for(int i=1;i<=n;i++){
      dis[i]=(int)1e9;
   }
   priority_queue<pair<int,int> >pq;
   pq.push(make_pair(0,s));
   dis[s]=0;
   while(!pq.empty()){
      int u=pq.top().second;
      int u_cost=-pq.top().first;
      pq.pop();
      if(dis[u]<u_cost)continue;
      for(int i=0;i<(int)adj[u].size();i++){
         int v=adj[u][i].second;
         int v_cost=adj[u][i].first;
         if(dis[v]>(u_cost+v_cost)){
            dis[v]=(u_cost+v_cost);
            pq.push(make_pair(-dis[v],v));
         }
      }
   }
   int l;
   scanf("%d",&l);
   int ans=0;
   for(int i=1;i<=n;i++)if(dis[i]==l)ans++;
   for(int i=1;i<=m;i++){
      int u=x[i],v=y[i];
      int cost=l-dis[u];
      if( cost>0 && cost<w[i] && w[i]-cost+dis[v] >= l)ans++;
      int v_cost=l-dis[v];
      if(v_cost>0 && v_cost<w[i] && w[i]-v_cost+dis[u] >l)ans++;
   }
   printf("%d",ans);
}