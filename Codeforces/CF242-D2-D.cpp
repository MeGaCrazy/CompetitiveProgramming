/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Sep 29 00:01:40 2018
*   @Idea :   just move on if current counter is should click . then click it and increase it's neighbors counters by one
*             if should click add to the queue to do the same process.
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;


const int N=1e5+7;
vector<int>adj[N];
int cnt[N],v[N];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
      int n,m;
      scanf("%d %d",&n,&m);
      for(int i=0;i<m;i++){
         int a,b;
         scanf("%d %d",&a,&b);
         adj[a].push_back(b);
         adj[b].push_back(a);
      }

      queue<int>q;
      for(int i=1;i<=n;i++){
         scanf("%d",&v[i]);
         if(v[i]==0){
           q.push(i);
         }
      }
      set<int>ans;
      while(!q.empty()){
         int node=q.front();
         q.pop();
         if(v[node]!=cnt[node])continue;
         ans.insert(node);
         cnt[node]++;
         for(int child : adj[node]){
               cnt[child]++;
               if(cnt[child]==v[child])q.push(child);
         }
      }
      printf("%d\n",ans.size());
      bool first=0;
      for(int c : ans){
        if(first)printf(" ");
        first=1;
        printf("%d",c);
      }



}