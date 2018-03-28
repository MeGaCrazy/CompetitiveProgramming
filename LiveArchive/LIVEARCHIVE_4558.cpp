/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Mar 28 11:35:22 2018
*   @Idea :    Usual ConvexHull imp but to satisfy his standard order must Check cross >0 :) 
*
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
  point operator -(point &other){
      return point(x-other.x,y-other.y);
  }
  inline bool operator <(point &other){
            if(fabs(y-other.y)==0 )
                    return x < other.x;
             return y > other.y;
  }

};
const int N=105;
point ans[N],arr[N];

long long cross(point v1,point v2){
    return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
vector<point>modify(int n){
     sort(arr,arr+n);
     int st=0,sz=0;
     for(int i=0;i<n;i++){
         while(sz-st>=2&& cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])>=0)sz--;
         ans[sz++]=arr[i];
     }
     st=--sz;
     for(int i=n-1;i>=0;i--){
         while(sz-st>=2&&cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])>=0)sz--;
         ans[sz++]=arr[i];
     }
     vector<point>v(ans,ans+sz);
 //   reverse(v.begin(),v.end());
     return v;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
       int n,cn;
       scanf("%d %d",&cn,&n);
       for(int i=0;i<n;i++){
          scanf("%d %d",&arr[i].x,&arr[i].y);
       }
       vector<point>ret=modify(n);
       printf("%d %d\n",cn,(int)ret.size()-1);
       for(int i=0;i<ret.size()-1;i++){
            printf("%d %d\n",ret[i].x,ret[i].y);
       }    
    }





}