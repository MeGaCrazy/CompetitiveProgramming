/*
*   Idea : First sort input acc in time and probability 
*          Second for each one try to add to him prev one his euclidean distance <= difference in Time  
*          Happy Solving :)
*/
#include <bits/stdc++.h>
using namespace std;
const int N=2005;
double dp[N];
vector< pair< pair<int,double>,pair<int,int> > >v;
int x[N],y[N],t[N];
double p[N];


int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
      int n;
      scanf("%d",&n);
      for(int i=0;i<n;i++){
         int X,Y,T;
         double P;
         scanf("%d %d %d %lf",&X,&Y,&T,&P);
         v.push_back(make_pair(make_pair(T,P),make_pair(X,Y)));
      }
      sort(v.begin(),v.end());
      for(int i=0;i<n;i++){
        x[i]=v[i].second.first;
        y[i]=v[i].second.second;
        p[i]=v[i].first.second;
        t[i]=v[i].first.first;
      }
      double ans=0.0;
      for(int i=0;i<n;i++){
         dp[i]=p[i];
         for(int j=0;j<i;j++){
           int xx=x[i]-x[j],yy=y[i]-y[j];
           int tt=t[i]-t[j];
           if( (xx*xx+yy*yy) <= (1ll*tt*tt))dp[i]=max(dp[i],dp[j]+p[i]);
         }
         ans=max(ans,dp[i]);
      }
      printf("%.8lf",ans);
}