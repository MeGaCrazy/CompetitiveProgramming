/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Mar 26 11:46:17 2018
*   @Idea :  Just Make ConvexHull And then Calcalute the Centroid..
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const double EPS=1e-6;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point &other){
    return point(x-other.x,y-other.y);
  }
  inline bool operator <(point &other){
     if( fabs(x-other.x) <EPS)
            return y < other.y -EPS;
      return x < other.x-EPS;
  }
};
double cross(point v1,point v2){
  return v1.x*v2.y-v1.y*v2.x;
}
const int N=105;
point arr[N];
int dcmp(double x,double y){
  return fabs(x-y) <EPS?0:x>y?1:-1;
}
vector<point>modify(int n){
    vector<point>poly(N,point());
    sort(arr,arr+n);
    int st=0,sz=0;
    for(int i=0;i<n;i++){
        if(sz-st >=2 && cross(poly[sz-2]-poly[sz-1],arr[i]-poly[sz-1])<=0)sz--;
        poly[sz++]=arr[i];
    }
    st=--sz;
    for(int i=n-1;i>=0;i--){
      if(sz-st>=2 && cross(poly[sz-2]-poly[sz-1],arr[i]-poly[sz-1])<=0)sz--;
      poly[sz++]=arr[i];
    }
    vector<point>ret;
    for(int i=0;i<sz;i++){
        ret.push_back(poly[i]);
    }
    return ret;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   freopen("out","w",stdout);
#endif
    int n;
    while(scanf("%d",&n)==1,n){
      if(n<3)break;
      for(int i=0;i<n;i++){
          scanf("%lf %lf",&arr[i].x,&arr[i].y);
      }
      vector<point>ret=modify(n);
      double area=0,x=0,y=0;
      for(int i=0;i<ret.size()-1;i++){
        int ii=i+1;
        double c=cross(ret[i],ret[ii]);
        area+=c;
        x+=(ret[i].x+ret[ii].x)*c;
        y+=(ret[i].y+ret[ii].y)*c;
      }
      if(dcmp(area,0)==0){
        printf("%.3f %.3f\n",(ret[0].x+ret[ret.size()-2].x)/2.0,(ret[0].y+ret[ret.size()-2].y)/2.0);
        continue;
      }
      area/=2.0;
      x/=6.0*area;
      y/=6.0*area;
      if(dcmp(x,0)==0)x=0;
      if(dcmp(y,0)==0)y=0;
      printf("%.3f %.3f\n",x,y);
    }
}