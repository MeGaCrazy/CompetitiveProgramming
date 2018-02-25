/**
*   @Author : MeGaCrazy
*   @InitTime : Sun Feb 25 12:37:39 2018
*   @Idea :  Just Check if inside using summing of Area of this point to each pair of triangle points.. 
*            if It equal area of total triangle return 1
*   Corner Case : 1-if the area = 0 then check if point on this point or segment using ccw :) 
*                 2- Take Care of bounderies of loops ..
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
double EPS=1e-5;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  bool operator <(point &other){
      return (y < other.y -EPS || (fabs(y-other.y) <EPS && x < other.x -EPS));
  }
  point operator -(point &other){
     return point(x-other.x,y-other.y);
  }
};

double cross(point &v1,point &v2){
   return v1.x*v2.y-v2.x*v1.y;
}
double norm(point &v1){
    return sqrt((v1.x*v1.x)+(v1.y*v1.y));
}
double ccw(point &a,point &b,point c){
   point v1=b-a;
   point v2=c-a;
   if(cross(v1,v2) >EPS)return 1;
   if(cross(v1,v2) < -EPS)return -1;
   if(v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
   if(norm(v1) < norm(v2) -EPS)return 1;
   return 0;
}
point pt[3];

bool Contain(point cur){ 
  double part=0;
  for(int i=0;i<3;i++){
    point v1=pt[i]-cur;
    point v2=pt[(i+1)%3]-cur;
    part+=fabs(cross(v1,v2));
  }
  point v1=pt[1]-pt[0];
  point v2=pt[2]-pt[0];
  double total=fabs(cross(v1,v2));
  if(fabs(total-part) < EPS && (total >0 || ccw(pt[0],pt[1],cur)==0||ccw(pt[0],pt[2],cur)==0||
    ccw(pt[1],pt[2],cur)==0))return 1;
  return 0;
}
point low, high;
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif

     while(1){
        int cnt=0;
        int maxx=-1,minx=1e9,maxy=-1,miny=1e9;
        for(int i=0;i<3;i++){
           scanf("%lf %lf",&pt[i].x,&pt[i].y);
           if(fabs(pt[i].x)<EPS && fabs(pt[i].y) <EPS)cnt++;
           low.x = min(low.x, pt[i].x), high.x = max(high.x, pt[i].x);
           low.y = min(low.y, pt[i].y), high.y = max(high.y, pt[i].y);
        }
        if(cnt==3)break;
        int c[4];
        c[0] = (int) max(1.0, floor(low.x));
        c[1] = (int) min(99.0, floor(high.x) + 1);
        c[2] = (int) max(1.0, floor(low.y));
        c[3] = (int) min(99.0, floor(high.y) + 1);
        int ans=0;
        for(int i = c[0]; i <= c[1]; i++){
           for(int j = c[2]; j <= c[3]; j++){
              if(Contain(point(i,j)))ans++;
           }
        }
      printf("%4d\n",ans);
     }




}