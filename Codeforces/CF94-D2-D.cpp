/*
*
*     Just simply first calculate the volume for each cup and then Just try to Put the some volume from 
*     bottle that has minimal milk :) 
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=55;
vector<pair<int,double> >ans[N];
double dis[N];
int use[N];
int main(){
    int n,w,m;
    scanf("%d %d %d",&n,&w,&m);
    double d=(n*w)/1.0/m;
    priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > >pq;
    for(int i=n;i>=1;i--){
        pq.push(make_pair(w,i));
    }
    for(int i=1;i<=m;i++){
          for(int j=0;j<n;j++){
             double cost=pq.top().first;
             int bottle=pq.top().second;
             double need=d-dis[i];
            // cerr<<i<<" dis is "<<dis[i]<<endl; 
             if((cost)<=1e-6){pq.pop();continue;}
             if(need<=(1e-6))break;
             if((need-cost)>=(1e-6)){
             //  cerr<<i<<" => "<<bottle<<" dis "<<dis[i]<<" cost "<<cost<<endl;
              use[bottle]++;
               dis[i]+=cost;
               ans[i].push_back(make_pair(bottle,cost));
               pq.pop();
             }     
             else if((need-cost)<(1e-6)){
                 dis[i]+=need;
                 use[bottle]++;
               //  cerr<<"error "<<cost<<" "<<need<<endl;
               //  cerr<<" hoi "<<i<<" => "<<bottle<<" dis "<<dis[i]<<" cost "<<cost-need<<endl;
                 ans[i].push_back(make_pair(bottle,need));
                 pq.pop();
                 pq.push(make_pair(cost-need,bottle));
             }
        }
    }
    for(int i=1;i<=n;i++){
      if(use[i]>=3){
         puts("NO");
         return 0;
      }
    }
   puts("YES");
    for(int i=1;i<=m;i++){
       for(int j=0;j<(int)ans[i].size();j++){
                 if(j!=0)printf(" ");
           printf("%d %.8f",ans[i][j].first,ans[i][j].second);
       }
       puts("");
    }
}