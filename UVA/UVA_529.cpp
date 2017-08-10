#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int p[N],dis[N];
int n;
bool check(int i,const set<int> &s){
      set<int>::iterator itr=s.begin();
      for(;itr!=s.end();itr++){
          if(s.count(i-(*itr)))return 1;
      }
      return 0;
}
void ans(const set<int>&s){
     set<int>::iterator itr=s.begin();
     for(;itr!=s.end();itr++){
        printf(*itr==n?"%d":"%d ",*itr);
     }
}
set<int> bfs(){
    for(int i=1;i<=n;i++){
       dis[i]=2e9;
    }
    queue< pair<int,pair<int,set<int> > > >pq;
    dis[1]=0;
    set<int>t;
    t.insert(1);
    pq.push(make_pair(0,make_pair(1,t)));
    int minsz=1e9;
    set<int>ret;
    while(!pq.empty()){
        int u=pq.front().second.first;
        int u_cost=pq.front().first;
        set<int>s=pq.front().second.second;
        pq.pop();
        if(u==n&&(int)s.size()<minsz){
           minsz=(int)s.size();
           ret=s;
        }
        if(u>=n)continue;
        if(dis[u]<u_cost)continue;
        for(int v=u+1;v<=2*u&&v<=n;v++){
            if(dis[v]>u_cost+1){
                if(v&1){
                   if(check(v,s)){
                     s.insert(v);
                     dis[v]=u_cost+1;
                     pq.push(make_pair(dis[v],make_pair(v,s)));
                   }
                }else{
                   if((s.count(v/2)||check(v,s))){
                     s.insert(v);
                     dis[v]=u_cost+1;
                     pq.push(make_pair(dis[v],make_pair(v,s)));
                   }
                }
           }
        }
    }
    return ret;
}



int main(){
#ifndef ONLINE_JUDGE
         freopen("in","r",stdin);
#endif
      while(scanf("%d",&n),n){
          ans(bfs());
          fprintf(stderr,"run time is %d ms\n",(int)clock());
          puts("");
     }

}                 
