/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Dec 29 11:42:50 2017
*   @Idea :   The Problem required computing this formula for each element  
*              constant1 rank < referee < constant2 rank or constant1 rank > referee > constant2 rank 
*             so for each referee = No of Constant smaller in rank *  No of Constant higher in rank
*                                  +  And vice versa  
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int bit[N];
int const MaxN=20005;
int ls[MaxN];
int rs[MaxN];
int a[MaxN];
void update(int idx){
     while(idx <=N){
        bit[idx]++;
        idx +=(idx & -idx);
     }
}
int Query(int idx){
  int ret=0;
  while(idx >0){
    ret+= bit[idx];
    idx-=(idx & -idx);
  }
  return ret;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
//   freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t); 
     int n;
     while(t--){
       memset(bit,0,sizeof(bit));
       scanf("%d",&n);
       for(int i=0;i<n;i++){
         scanf("%d",&a[i]);
         ls[i]=Query(a[i]);
         update(a[i]);
       }
       memset(bit,0,sizeof(bit));
       for(int i=n-1;i>=0;i--){
          rs[i]=Query(a[i]);
          update(a[i]);
       }
       long long  ans=0;
       for(int i=0;i<n;i++){
          ans+=1ll*ls[i]*(n-i-1-rs[i])+1ll*rs[i]*(i-ls[i]);
       }
      printf("%lld\n",ans);
     }

}