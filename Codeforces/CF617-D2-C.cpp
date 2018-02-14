/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Feb 14 13:52:47 2018
*   @Idea :  Just Brute Force for every radius between the center1 and get the radius of max distance between other not included in first 
*            Circle ...and Minimize for every state 
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  int x,y;
  point(int x=0,int y=0):x(x),y(y){}

};
long long dis(int x,int y,int xx,int yy){
   return 1ll*(x-xx)*(x-xx)+1ll*(y-yy)*(y-yy);
}
const int N=2005;
point arr[N];
point c[2];
int n;
long long solve(int idx1,int idx2){
      long long ret=2e18;
      for(int i=0;i<n;i++){
           long long r=dis(c[idx1].x,c[idx1].y,arr[i].x,arr[i].y);
           long long r2=0;
           for(int j=0;j<n;j++){
              if(dis(c[idx1].x,c[idx1].y,arr[j].x,arr[j].y)>r){
               r2=max(r2,dis(c[idx2].x,c[idx2].y,arr[j].x,arr[j].y));
              }
           }
           ret=min(ret,r+r2);
      }
      return ret;
}

int main(){
#ifndef ONLINE_JUDGE
//   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     scanf("%d",&n);
     for(int i=0;i<2;i++){
       scanf("%d %d",&c[i].x,&c[i].y);
     }
     for(int i=0;i<n;i++){
         scanf("%d %d",&arr[i].x,&arr[i].y);
     }
     printf("%lld",min(solve(0,1),solve(1,0)));
}


