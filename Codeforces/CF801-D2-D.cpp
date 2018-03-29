/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Mar 29 13:18:11 2018
*   @Idea :   For making polygon Concave Just from Each three consective point Make i,i+1,i+2
*              Make line between i,i+2 and get the prependicualr distance between this line and point i+1 :)
*              The Idea u want to get Max distance so u move i,i+1 in direction of point i+2 ... And i+2 in the opposite direction :) 
*              Will Take distance to make it convave "The prependicular distance /2 " :)
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
  point operator +(point &other){
     return point(x+other.x,y+other.y);
  }
  point operator *(double f){
    return point(x*f,y*f);
  }
};
const int N=1005;
point arr[N];
double length(double x,double y,double xx,double yy){
      return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int dcmp(double x,double y){
  return fabs(x-y) <EPS?0:x>y?1:-1;
}
double dot(point &v1,point &v2){
  return v1.x*v2.x+v1.y*v2.y;
}
double disToSeg(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    double t1,t2;
    if((t1=dot(v1,v2))<= 0)return length(a.x,a.y,c.x,c.y);
    if((t2=dot(v1,v1))<= t1)return length(b.x,b.y,c.x,c.y);
    double f=t1/t2;
    point ret=v1*f+a;
    return length(ret.x,ret.y,c.x,c.y);
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int n;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
         scanf("%lf %lf",&arr[i].x,&arr[i].y);
     }
     double dis=1e18;
     for(int i=0;i<n;i++){
       int prv=(i-1+n)%n;
       int nxt=(i+1)%n;
       double tmp=disToSeg(arr[prv],arr[nxt],arr[i]);
       if(dcmp(tmp,dis)==-1)dis=tmp;
     }
     printf("%.6f\n",dis/2);

}