/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Mar 26 17:38:28 2018
*   @Idea :
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
      if(fabs(x-other.x) <EPS){
        return y < other.y -EPS;
      }
      return x < other.x -EPS;
  }

};
const int N=1e5+7;
point arr[N],ans[N];
double length(double x,double y,double xx,double yy){
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
double cross(point v1,point v2){
    return v1.x*v2.y-v1.y*v2.x;
}

vector<point>modify(int n){
    sort(arr,arr+n);
    int st=0,sz=0;
    for(int i=0;i<n;i++){
      while(sz-st >=2 && cross(ans[sz-2]-ans[sz-1],arr[i]-ans[sz-1])<=0)sz--;
      ans[sz++]=arr[i];
    }
    st=--sz;
    for(int i=n-1;i>=0;i--){
      while(sz-st >=2 && cross(ans[sz-2]-ans[sz-1],arr[i]-ans[sz-1])<=0)sz--;
       ans[sz++]=arr[i];
    }
    vector<point>v(ans,ans+sz);
    return v;
}
int dcmp(double x,double y){
   return fabs(x-y) <EPS?0:x>y?1:-1;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
      int n;
      double b=0;
      scanf("%lf %d",&b,&n);
      double len=0;
      for(int i=0;i<n;i++){
          scanf("%lf %lf",&arr[i].x,&arr[i].y);
      }
      vector<point>ret=modify(n);

      for(int i=0;i<ret.size()-1;i++){
         len+=length(ret[i].x,ret[i].y,ret[i+1].x,ret[i+1].y);
      }
      if(dcmp(len,b)!=1)len=b;
      printf("%.5f\n",len);
    }



}