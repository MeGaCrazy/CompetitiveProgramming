/*
*  target : cal the max size for all 4 bird from paper
*  sol   : easly u can see there are to secnario that first get min between a/4 (a is the Biggest) ,b 
           to avoid choose a/4 is less than b that now not square
*          second check if take min between a/2 b/2 is big than the first or not 
*/

#include <bits/stdc++.h>
using namespace std;



int main(){
     int n;
     while(scanf("%d",&n),n){
         double bestans=-1.0;
         int ret=0;
         for(int i=0;i<n;i++){
           double a,b;
           scanf("%lf %lf",&a,&b);
           if(a<b)swap(a,b);
           double cal=max(min(a/4.0,b),min(a/2.0,b/2.0));
           if(cal>bestans){
             bestans=cal;
             ret=i+1;
           }
         }
         printf("%d\n",ret);
     
     }



}
