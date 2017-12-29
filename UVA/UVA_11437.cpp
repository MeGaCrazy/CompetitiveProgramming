/**
*   @Author : MeGaCrazy
*   @InitTime : Sun Dec 03 02:04:30 2017
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
struct point{
 double x,y;
point  operator - (point &b){
    return {b.x-x,b.y-y};
}
point  operator / (double f) {
    return {x/f,y/f};
}                                                                                 
point  operator + (point &b) {
         return {b.x+x,b.y+y};
}
point operator * (double f){
     return {x*f,y*f};
}

};
point Get_point(point &a,point &b){
     point f = b-a;
     point tmp = f/3.0;
     return a + tmp;
}
point ft[3];
point sn[3];
point en[3];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
//   freopen("out","w",stdout);
#endif
      int t;
      scanf("%d",&t);
      while(t--){
           for(int i=0;i<3;i++){
              scanf("%lf %lf",&ft[i].x,&ft[i].y);
           }
           for(int i=0;i<3;i++){
             st[i]=ft[i] + (ft[(i+1)%3]-ft[i]) / 3.0;
           }
           for(int i=0;i<3;i++){
             en[i]
           }


      }



}