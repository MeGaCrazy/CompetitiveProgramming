/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Feb 23 12:57:33 2018
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
   long long a,b,Cas=1;
   while(scanf("%lld %lld",&a,&b),(a+b)){
   printf("Case %lld:",Cas++);
   a=a*(a-1)/2;
   b=b*(b-1)/2;
   printf(" %lld\n",a*b);
   }
   



}