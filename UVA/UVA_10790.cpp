/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Feb 23 12:57:33 2018
*   @Idea :   When Intersection Point made ..!!! 1    2      That mean to make intersection point u need pair of first row and pair of second row
*                                                  \/
*                                                  /\
*                                                1    2
*           
*            So how Many Different pair in any Row Simply th (n) chose 2 ,,,, mean n*(n-1)/2
*            so to know the number of different intersection Just Mutliply the number of Different Pair in both..
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
   long long a,b,Cas=1;
   while(scanf("%lld %lld",&a,&b),(a+b)){
   printf("Case %lld:",Cas++);
   a=a*(a-1)/2;
   b=b*(b-1)/2;
   printf(" %lld\n",a*b);
   }
   



}