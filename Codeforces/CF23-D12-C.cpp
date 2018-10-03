/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Sep 29 00:31:48 2018
*   @Idea :   Sort in asc according to orange then apple . check if sum of apple in odd element  > half then that's the answer
*             otherwise take the even element + the last element in Odd.
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+7;
bool vis[N];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
      int t;
      scanf("%d",&t);
      while(t--){
         int n;
         scanf("%d",&n);
         long long aa=0;
         long long bb=0;
         vector<pair<int,pair<int,int> > >v;
         for(int i=0;i<2*n-1;i++){
             int a,b;
             scanf("%d %d",&a,&b);
             v.push_back(make_pair(a,make_pair(b,i+1)));
             aa+=a;
             bb+=b;
         }
         sort(v.begin(),v.end());
         long long suma=0;
         long long sumb=0;
         set<int>ans;
         for(int i=0;i<2*n-1;i+=2){
              suma+=v[i].first;
              sumb+=v[i].second.first;
              ans.insert(v[i].second.second);
         }
         if(suma >= (aa+1)/2 && sumb >= (bb+1)/2){
         }else{
            ans.clear();
            suma=0;
            sumb=0;
            for(int i=1;i<2*n-1;i+=2){
              suma+=v[i].first;
              sumb+=v[i].second.first;
              ans.insert(v[i].second.second);
            }
            suma+=v[2*n-2].first;
            sumb+=v[2*n-2].second.first;
            ans.insert(v[2*n-2].second.second);
         
         }

       if(suma >= (aa+1)/2 && sumb >= (bb+1)/2){
  	     printf("YES\n");
             bool first=0;
             for(int c:ans){
                  if(first)printf(" ");
                  first=1;
                  printf("%d",c);
             }
             printf("\n");
      
      }else{
        printf("NO\n\n");
      }	
   }
}