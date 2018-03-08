/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Mar 08 22:31:35 2018
*   @Idea :  Just Calculate Consective Range area and Response to each Query
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
};
const double EPS=1e-4;
const int N=50005;
point arr[N];
int n,q;
int dcmp(double x,double y){
   return fabs(x-y) <EPS?0:x>y?1:-1;
}

double cross(point &v1,point &v2){
    return v1.x*v2.y-v1.y*v2.x;
}
double sum[N];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
  
    bool ok=0;
    while(scanf("%d %d",&n,&q),(n+q)){
        if(ok){
          puts("");
        }
        ok=1;
        for(int i=0;i<n;i++){
          scanf("%lf %lf",&arr[i].x,&arr[i].y);
        }
        arr[n]=arr[0];
        sum[0]=0;
        for(int i=0;i<n;i++){
          sum[i+1]=cross(arr[i],arr[i+1]);
          sum[i+1]+=sum[i];
        }
        while(q--){
           int x,y;
           scanf("%d %d",&x,&y);           
           double left=fabs(sum[y]-sum[x]+cross(arr[y],arr[x]));
           double right=fabs(sum[n])-left;
        
           left/=2.0,right/=2.0;
           if(dcmp(left,right)==-1){
               printf("%.1f\n",left);
           }else{
              printf("%.1f\n",right);
           }
          }
    
    }

}