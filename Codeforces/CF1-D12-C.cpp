/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Mar 02 15:57:27 2018
*   @Idea :  First Just Get the center of Circle and Radius using usual algorithm now let's go for exciting part 
*            Iterate For Every n from 3 to 100
*            we now the angle between 2 consective vertices and center of polygon equal 2*pi/n
*            and for every pair of vertix has mutiple of 2 * pi/n  :) 
*
*            Just check the angles of every pair of given point if it multiple of 2*pi/n then n is  the answer
*         
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point other){
     return point(x-other.x,y-other.y);
  }
  point operator +(point other){
     return point(x+other.x,y+other.y);
  }
  point operator *(double f){
     return point(x*f,y*f);
  }
};
const double EPS=1e-5;
double length(point v){
  return sqrt((v.x*v.x)+(v.y*v.y));
}
double cross(point &v1,point &v2){
   return v1.x*v2.y-v1.y*v2.x;
}
point Inter(point &a,point &b,point &c,point &d){
  point u=b-a;
  point v=d-c;
  point w=a-c;
  double t1=cross(v,w)/cross(u,v);
//  cerr<<" "<<t1<<endl;
  point ret=(u*t1)+a;
  return ret;
}
pair<double,point>FindCircle(point &a,point &b,point &c){
  point v1=b-a;
  point v2=c-a;
  point prv1=point(v1.y,-v1.x);
  point prv2=point(v2.y,-v2.x);
  point mid1=(b+a)*0.5;
  point mid2=(c+a)*0.5;
  point end1=mid1+prv1;
  point end2=mid2+prv2;
  point ret=Inter(mid1,end1,mid2,end2);
  return make_pair(length(ret-a),ret);
}
const double pi=acos(-1);
double fixangle(double x){
    return x>1?1:x<-1?-1:x;
}
double dot(point &v1,point &v2){
    return v1.x*v2.x+v1.y*v2.y;
}
double getangle(point &v1,point &v2){
    return acos(fixangle(dot(v1,v2)/length(v1)/length(v2)));
}
bool isInt(double x){
     int xx=(int)(x+EPS);
      return fabs(x-xx) <EPS;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    point pt[3];
    for(int i=0;i<3;i++){
       scanf("%lf %lf",&pt[i].x,&pt[i].y);
    }
    pair<double,point>ret=FindCircle(pt[0],pt[2],pt[1]);
    double R=ret.first;
    point cen=ret.second;
    point a=cen-pt[0];
    point b=cen-pt[1];
    point c=cen-pt[2];
    double a1=getangle(a,b);
    double a2=getangle(a,c);
    for(int n=3;n<=200;n++){
       double tt=2*pi/n;
       if(!isInt(a1/tt)||!isInt(a2/tt))continue;
       double ans=0.5*n*R*R*sin(tt);
       printf("%.6f",ans);
       return 0;
    }



}