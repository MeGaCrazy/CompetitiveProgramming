/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Feb 10 12:18:14 2018
*   @Idea :  Circle is Just speical case of eclipse then the area of circle is = pi*r*r in eclipse the area is =pi*a*b
*            a is minor axes and b is major one
*            Just make one minor and then from triangle equation get the major :) 
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
  // freopen("out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    const double pi=2*acos(0);
    while(n--){
       double D,L;
       scanf("%lf %lf",&D,&L);
       D/=2,L/=2;
       double a=L;
       double c=D;
       double b=sqrt(a*a-c*c);
       printf("%.3f\n",pi*a*b);
    }



}