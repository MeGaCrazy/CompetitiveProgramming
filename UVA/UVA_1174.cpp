#include <bits/stdc++.h>
using namespace std;
typedef vector<int>vi;
class ufds{
  private:vi p,rank;
  public:
    ufds(int n){
       p.assign(n+1,0);
       rank.assign(n+1,0);
       for(int i=0;i<=n;i++){
          p[i]=i,rank[i]=1;
      }
  }
  int findSet(int i){
      return p[i]==i?i:p[i]=findSet(p[i]);
  }
  bool isSame(int i,int j){
    return findSet(i)==findSet(j);
  }
  void join(int i,int j){
     int x=findSet(i),y=findSet(j);
     if(isSame(x,y))return;
     if(rank[x]>=rank[y]){
         p[y]=p[x];
         rank[x]++;
     }else{
      p[x]=p[y];
     }
  }

};

int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        ufds uf(n+1);
        map<string,int>mp;
        int nodes=0,cost;
        char s1[10]={},s2[10]={};
        vector<pair<int,pair<int,int > > >edges;
        for(int i=0;i<m;i++){
             scanf("%s %s %d",&s1,&s2,&cost);
             if(!mp[s1])mp[s1]=++nodes;
             if(!mp[s2])mp[s2]=++nodes;
             edges.push_back(make_pair(cost,make_pair(mp[s1],mp[s2])));
        }
        sort(edges.begin(),edges.end());
        int ans=0,cnt=0;
        for(int i=0;i<(int)edges.size()&&(cnt+1!=n);i++){
            if(!uf.isSame(edges[i].second.first,edges[i].second.second)){
               uf.join(edges[i].second.first,edges[i].second.second);
               ans+=edges[i].first;
               cnt++;
            }
        }
         printf("%d\n",ans);
         if(t)printf("\n");
    }
}