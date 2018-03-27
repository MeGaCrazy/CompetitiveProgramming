/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Mar 27 10:31:08 2018
*   @Idea :  Get The Area of convexhull and area of tile then get the percentage :) 
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const double EPS=1e-5;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point &other){
         return point(x-other.x,y-other.y);
  }
  inline bool operator <(point &other){
          if( fabs(x-other.x ) <EPS){
              return y < other.y -EPS;
          }
          return x < other.x  -EPS;
  }
};
const int N=105;
point ans[N<<1],arr[N];

double cross(point v1,point v2){
      return v1.x*v2.y-v1.y*v2.x;
}

vector<point>modify(int n){
      sort(arr,arr+n);
      int st=0,sz=0;
      for(int i=0;i<n;i++){
         while(sz-st >=2 && cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])<=0)sz--;
         ans[sz++]=arr[i];
      }
      st=--sz;
      for(int i=n-1;i>=0;i--){
         while(sz-st >=2&& cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])<=0)sz--;
         ans[sz++]=arr[i];
      }
      vector<point>ret(ans,ans+sz);
      return ret;     
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int n,Cas=1;
    while(scanf("%d",&n),n){
        printf("Tile #%d\n",Cas++);
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&arr[i].x,&arr[i].y);
        }
        double area=0,subarea=0;
        for(int i=0;i<n;i++){
          int ii=(i+1)%n;
          subarea+=cross(arr[i],arr[ii]);
        }
        subarea=fabs(subarea);
        vector<point>ret=modify(n);
        for(int i=0;i<(int)ret.size()-1;i++){
          area+=cross(ret[i],ret[i+1]);
        }
        area=fabs(area);
        subarea=area-subarea;
        double f=(subarea/area)*100;
        printf("Wasted Space = %.2f %\n",f);
        puts("");
    }



}