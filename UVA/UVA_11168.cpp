/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Mar 27 11:24:18 2018
*   @Idea :    The Best Position of AirPort is the Convexhull edges that Statsify all statements .. 
*              Then Get the Average distance from original point to this edge ...(try every edge in convexhull And minimize ):) 
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
       if(fabs(x-other.x) <EPS){
             return y < other.y -EPS;
       }
       return x < other.x -EPS;
  }
  point operator +(point &other){
          return point(x+other.x,y+other.y);
  }
  point operator *(double f){
        return point(x*f,y*f);
  }
};
const int N=10005;
point arr[N],ans[N<<1];
double cross(point v1,point v2){
    return v1.x*v2.y-v1.y*v2.x;

}
int dcmp(double x,double y){
       return fabs(x-y) <EPS?0:x>y?1:-1;
}
vector<point>modify(int n){
      sort(arr,arr+n);
      int st=0,sz=0;
      for(int i=0;i<n;i++){
         while(sz-st >=2 && cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2]) <=0)sz--;
         ans[sz++]=arr[i];
      }
      st=--sz;
      for(int i=n-1;i>=0;i--){
        while(sz-st>=2 && cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])<=0)sz--;
        ans[sz++]=arr[i];
      }
      vector<point>ret(ans,ans+sz);
      return ret;
}
double length(double x,double y,double xx,double yy){
         return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

double dot(point &v1,point &v2){
   return v1.x*v2.x+v1.y*v2.y;
}
double disToline(point &a,point  &b,point &c){
   double dis=cross(b-a,c-a)/length(a.x,a.y,b.x,b.y);
   return fabs(dis);
}
double solve(int n,point &a,point &b){
     double ret=0;
     for(int i=0;i<n;i++){
         ret+=disToline(a,b,arr[i]);
     }
     return ret/(n);

}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t,Cas=1;
     scanf("%d",&t);
     while(t--){
       int n;
       scanf("%d",&n);
       for(int i=0;i<n;i++){
          scanf("%lf %lf",&arr[i].x,&arr[i].y);
       }
       vector<point>ret=modify(n);
       double len=1e18;
       for(int i=0;i<(int)ret.size()-1;i++){
          double tt=solve(n,ret[i],ret[i+1]);
          if(dcmp(tt,len)==-1)len=tt;
       }
       if(dcmp(len,1e18)==0)len=0;
       printf("Case #%d: %.3f\n",Cas++,len);
     }

}