/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Jun 22 08:00:33 2018
*   @Idea :   Using trigonometry rules to get the area 
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
   double l,w,h,angle ;
   while(scanf("%lf %lf %lf %lf",&l,&w,&h,&angle)==4){
      angle=angle/180.0*acos(-1);
      double newh=tan(angle)*l;
      if(newh <=h){
       printf("%.3f mL\n",l *w*h-(.5*newh*l*w));

      }else{
         angle=(acos(-1)*0.5 - angle);
         double newl=h*tan(angle);
         printf("%.3f mL\n",newl*h*.5*w);
      
      }
   }


}