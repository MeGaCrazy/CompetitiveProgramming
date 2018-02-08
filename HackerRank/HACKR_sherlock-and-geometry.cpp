/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Feb 08 11:30:22 2018
*   @Idea :    Just Check if there's intersect Between the triangle and circle using usual equations and Take Care that On Seg 
*              Or Not
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
  int  r;
  point(double x=0,double y=0,int r=0):x(x),y(y),r(r){}
  point operator -(point &other){
       return point(x-other.x,y-other.y);
  }                              
};
const double EPS=1e-5;
int dcmp(double x,double y){
   return fabs(x-y)<EPS?0:x>y?1:-1;
}
const int N=3;

point arr[N];
double dot(point v1,point v2){
    return v1.x*v2.x+v1.y*v2.y;
}

bool Inter(point &p0,point &p1,point &p2){
       point v1=p1-p0;
       point v2=p0-p2;
       double a=dot(v1,v1);
       double b=2*dot(v1,v2);
       double c=dot(v2,v2)-p2.r*p2.r;
       double f=b*b - 4*a*c;

       if(dcmp(f,0)>=0){
          double t1=((-b+sqrt(f))/(2*a));
          double t2=((-b-sqrt(f))/(2*a));
          if((dcmp(t1,1)==1||dcmp(t1,0)==-1)&&(dcmp(t2,1)==1||dcmp(t2,0)==-1))return 0;
           return 1;
       }
       return 0;
}

int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
  // freopen("out","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
        point circ;
        scanf("%lf %lf %d",&circ.x,&circ.y,&circ.r);
        for(int i=0;i<N;i++){
           scanf("%lf %lf",&arr[i].x,&arr[i].y);
        }
        bool f=0;
        for(int i=0;i<N;i++){
            if(Inter(arr[i],arr[(i+1)%N],circ)){
               f=1;
               break;
            }
        }
       puts(f?"YES":"NO");
    }




}