/**
*   @Author : MeGaCrazy
*   @InitTime : Sun Feb 11 19:22:18 2018
*   @Idea :    Just using Heron Forumla get the area and then get the cos of each arc using cosin law :)
*              then total - arcs area = get the required area
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
double fix_angle(double v){
   return v>1?1:v<-1?-1:v;
}
double get_angle(double a,double b,double c){
    return acos( fix_angle((b*b+c*c-a*a)/(2*b*c)));
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
     const double pi=acos(-1);
     while(t--){
       double r1,r2,r3;
       scanf("%lf %lf %lf",&r1,&r2,&r3);
       double a=r1+r2;
       double b=r2+r3;
       double c=r1+r3;
       double s=(a+b+c)/2.0;
       double totalArea=sqrt(s*(s-a)*(s-b)*(s-c));
       double A=get_angle(a,b,c);
       double B=get_angle(b,a,c);
       double C=get_angle(c,a,b);
       printf("%lf\n",totalArea-(r3*r3*A+r1*r1*B+r2*r2*C)/2.0);
     }
}