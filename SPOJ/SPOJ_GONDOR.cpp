#include <bits/stdc++.h>
using namespace std;
const int N=105;
int x[N],y[N],arr[N];
double dis[N];
vector<int>light[N];
double di(int x,int y,int xx,int yy){
       return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
void bfs(int s){
      priority_queue<pair<double,int>,vector<pair<double,int>  >,greater<pair<double,int > > >q;
      for(int i=0;i<N;i++){
          dis[i]=1e9;
      }
      dis[s]=0.0;
      q.push(make_pair(0.0,s));
      while(!q.empty()){
           pair<double,int> u=q.top();
           q.pop();
           if(dis[u.second]<u.first)continue;
           int cnt=arr[u.second];
           for(int i=0;i<(int)light[u.second].size();i++){
               int v=light[u.second][i];
               double cal=di(x[u.second],y[u.second],x[v],y[v]);
               if(dis[v]>u.first&&cnt){
                    cnt--;
                   if(dis[v]>u.first+cal){
                                  cerr<<x[u.second]<<" => "<<y[u.second]<<" -  "<<x[v]<<" => "<<y[v]<<endl;
                                  cerr<<"cost "<<u.first<<" + "<<cal<<endl;
                      dis[v]=u.first+cal;
                      q.push(make_pair(dis[v],v));
                   }
               }
           }
      }
}
int main(){
#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
#endif
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",x+i,y+i,arr+i);
            for(int j=1,a;j<n;j++){
                scanf("%d",&a);
                light[i].push_back(a);
            }
        }
        bfs(1);
        for(int i=1;i<=n;i++){
            printf("%.6f\n",dis[i]);
        }

}