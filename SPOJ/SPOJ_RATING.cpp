/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Dec 28 18:59:17 2017
*   @Idea :     Just Sort ASC and and forget about First Column and Take The Second column
*               and put in Bit element by element and his rank = how many contestants before his rating "Cumlative sum From 0 to your Rank"
*           
*               Corner Case : You Must Count The onces whose rank are typical Like in statement " with at least one being greater"
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
const int N = 1e5+7;
int bt[N];
int ans[N*3];
int get(int idx){
  int ret=0;
   while(idx > 0){
      ret += bt[idx];
      idx -=(idx & - idx);
   }
   return ret;

}
void update(int idx,int value){
   while(idx <= N){
      bt[idx]+=value;
      idx +=(idx & - idx);
   }

}
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     vector<pair<int ,pair<int,int > > > v;
     int n; 
     scanf("%d",&n);
     for(int i=0;i<n;i++){
          int a,b;
          scanf("%d %d",&a,&b);
          v.push_back(make_pair(a,make_pair(b,i)));
     }
     sort(v.begin(),v.end());
     int cnt=0;
     for(int i=0;i<n;i++){
       int x= v[i].second.first;
       ans[v[i].second.second]=get(x);
       if(i>0 && v[i-1].first == v[i].first && v[i-1].second.first == v[i].second.first)cnt++;
       else cnt=0;
       ans[v[i].second.second]-=cnt;
       update(x,1);
     }
     for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
     }

}