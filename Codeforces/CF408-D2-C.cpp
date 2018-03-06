/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Mar 06 04:14:23 2018
*   @Idea :   Iterate for Every Point  you need Just iterate for  X and easily caculate y by eculdian distance  
*
*    Corner Cases: 1- Take Care of Sqrt of negative ..
*                  2- Must there's no pair of x or y equals
*                  3- the dot product musts =0 so they prependicular 
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
      int a,b;
      scanf("%d %d",&a,&b);
      for(int x1=-a;x1<=a;x1++){
         int ty1=abs(x1*x1-a*a);
         int y1=sqrt((double)ty1);
         if(y1 * y1 != ty1)continue;

         for(int x2=-b;x2<=b;x2++){
           int ty2=abs(x2*x2-b*b);
           int y2=sqrt((double)ty2);

           if(y2 * y2 != ty2)continue;
           if(x1==x2||y1==y2||x1==0||x2==0||y1==0||y2==0)continue;
           if(x1*x2+y1*y2!=0)continue; // dot must 0 Because the 2 vector are prependicular 

           printf("YES\n");
           printf("0 0\n%d %d\n%d %d",x1,y1,x2,y2);
           return 0;
         }
      }
      printf("NO");



}