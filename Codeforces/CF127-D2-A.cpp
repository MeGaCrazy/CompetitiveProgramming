/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Dec 29 10:09:30 2017
*   @Idea :  Just get eculdien distance between every two continus points and divide all by 50 then mult by k
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
//   freopen("out","w",stdout);
#endif
    int n,k;
    scanf("%d %d",&n,&k);
    double ans=0.0;
    double prev_x=0,prev_y=0;
    for(int i=0;i<n;i++){
      double x,y;
      scanf("%lf %lf",&x,&y);
      if(i>0){
        ans+=(sqrt((x-prev_x)*(x-prev_x)+(y-prev_y)*(y-prev_y)));
      } 
      prev_x=x;
      prev_y=y;
    }
    ans/=50.0;
    ans*=k;
    printf("%.9f",ans);

}