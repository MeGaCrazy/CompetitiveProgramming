/*
*  target : cal the minimum area within all possible pair of route
*     sol : at first look u can see that if we choose route [1,2],[1,3],[1,4] then the next step we only need to select
*           [2,3],[2,4] and so on so if u to make all possible route effeciently u can make it like disjoint sets
*           first there is a route between two compment so we can make routes between all pair of different component so
*           Just multiply number of Area at comp1 by comp2 :) and then with the route that connect them :) 
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=123456;
int p[N],siz[N],arr[N];
vector<pair<int,pair<int,int>  > >edges;
int Find(int i){
   return p[i]==i?i:p[i]=Find(p[i]);
}
bool isSame(int i,int j){
   return Find(i)==Find(j);
}
void join(int i,int j){
      int x=Find(i),y=Find(j);
      if(siz[x]>=siz[y]){
          p[y]=x;
          siz[x]+=siz[y];
      }else{
          p[x]=y;
          siz[y]+=siz[x];
      }
}
bool cmp(pair<int,pair<int,int > >u,pair<int,pair<int,int > >v){
    return u.first>v.first;
}
int main(){
      int n,m;
      scanf("%d %d",&n,&m);
      for(int i=1;i<=n;i++){
         scanf("%d",arr+i);
      }
      //clear 
      for(int i=0;i<=n;i++){
          p[i]=i;
          siz[i]=1;
      }
      for(int i=1,a,b;i<=m;i++){
         scanf("%d %d",&a,&b);
         edges.push_back(make_pair(min(arr[a],arr[b]),make_pair(a,b)));
      }

      sort(edges.begin(),edges.end(),cmp);
     long long ans=0.0;
      for(int i=0;i<m;i++){
            pair<int,pair<int,int> > u=edges[i];
            int cost=u.first;
            int a=u.second.first,b=u.second.second;
            if(!isSame(a,b)){
               ans+=(u.first*1ll*siz[Find(a)]*siz[Find(b)]);
               join(a,b);
            }
      }
      long double res=2.0*ans/(1.0*n*(n-1));
      cout << fixed << setprecision(12) << res << endl;     
}




/* Just Stupid Thinking :) =D 
#include <bits/stdc++.h>
using namespace std;
const int N=123456;
vector<int>adj[N];
map<pair<int,int>,int>vis;
int arr[N];
int n,m;
double bfs(int s,int t){
     queue<pair<int,int> >q;
     q.push(make_pair(s,arr[s]));
     while(!q.empty()){
         int u=q.front().first;
         int cost=q.front().second;
         q.pop();
         if(u==t)return (double)cost;
         for(int i=0;i<(int)adj[u].size();i++){
             int v=adj[u][i];
              q.push(make_pair(v,min(cost,arr[v])));
         }
     }

    return 0.0;
}
int main(){

     scanf("%d %d",&n,&m);
     for(int i=1;i<=n;i++){
        scanf("%d",arr+i);
     }
     double sum=0.0;
     for(int i=1,a,b;i<=m;i++){
         scanf("%d %d",&a,&b);
         adj[a].push_back(b);
         adj[b].push_back(a);
         vis[make_pair(a,b)]=1;
         vis[make_pair(b,a)]=1;
         sum+=min(arr[a],arr[b]);
     }
     for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
               if(!vis[make_pair(i,j)]){
                sum+=bfs(i,j);
                }
        }
     }
     sum*=2.0;
     printf("%.6f\n",(double)((sum)/(double)(n*(n-1))));

}
*/