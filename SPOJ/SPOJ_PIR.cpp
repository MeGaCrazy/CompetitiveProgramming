/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Jun 19 00:31:29 2018
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


int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
     while(t--){
       double U,V,W,u,v,w;
       scanf("%lf %lf %lf %lf %lf %lf",&w,&v,&u,&U,&V,&W);
       double X=(w-U+v)*(U+v+w);
       double x=(U-v+w)*(v-w+U);
       double Y=(u-V+w)*(V+w+u);
       double y=(V-w+u)*(w-u+V);
       double Z=(v-W+u)*(W+u+v);
       double z=(W-u+v)*(u-v+W);
       double a=sqrt(x*Y*Z);
       double b=sqrt(y*Z*X);
       double c=sqrt(z*X*Y);
       double d=sqrt(x*y*z);
       double ans=sqrt((-a+b+c+d)*(a-b+c+d)*(a+b-c+d)*(a+b+c-d))/(192.0*u*v*w);
       printf("%.4f\n",ans);
     }



}