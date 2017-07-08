/*
*  target: check if can put (n) inner circles in Big One 
*  sol : first check if 2*r > R then it must fit for 1 only so if n==1 yes otherwise no
*        second if R <r it must no for any n .. 
         third check if sum of all angle that all circle take from the center of Circle < 2*pi then Yes otherwise no
*/

#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);

int main(){
     int r,R,n;
     scanf("%d %d %d",&n,&R,&r);
     if(R>=r&&r*2>R){
          if(n==1){printf("YES");return 0;}
          else {printf("NO");return 0;}
     }
     if(R<r){
       printf("NO");
     }else{
      double theta=2.0*asin((double)r/(double)(R-r))*n;
      if(theta-2*pi<1e-9){
          printf("YES");
       }else{
          printf("NO");
       }
     
    }
}