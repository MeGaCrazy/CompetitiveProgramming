/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Feb 09 09:51:05 2018
*   @Idea :  Just Calculate summation of all distance and then Iterate if point in segment get the point on seg if not
*            remove the previous seg distance from soFarDistance and repeat
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
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point &other){
          return point(x-other.x,y-other.y);
  }
  point operator *(double f){
      return point(x*f,y*f);
  }
  point operator +(point &other){
       return point(x+other.x,y+other.y);
  }

};
const int N=105;
point arr[N];
double cost[N];
const double EPS=1e-6;
int dcmp(double x,double y){
    return fabs(x-y)<EPS?0:x>y?1:-1;
}
double dis(double x,double y,double xx,double yy){
      return  sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
void solve(double soFar,point &a,point &b,double c){
     point v=b-a;
     double t1=soFar/c;
     point ret=(b-a)*t1+a;
     printf("%.2f %.2f\n",ret.x,ret.y);
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
    int n,k,t;
    scanf("%d",&n);
    for(int Cas=1;Cas<=n;Cas++){
         printf("Road #%d:\n",Cas);
         scanf("%d %d",&k,&t);
         for(int i=0;i<k;i++){
             scanf("%lf %lf",&arr[i].x,&arr[i].y); 	
         }
         double total=0;
         for(int i=0;i<k-1;i++){
            cost[i]=dis(arr[i].x,arr[i].y,arr[i+1].x,arr[i+1].y);
            total+=cost[i];
         }
         double inc=total/(double)(t-1);
         int m=0;
         double soFar=0;
         int i=0;
         while(m<t){
            if(dcmp(soFar,cost[i])!=1){
               solve(soFar,arr[i],arr[i+1],cost[i]);
               m++;
               soFar+=inc;
            }else{
               soFar-=cost[i];
               i++;
            }
         }
        puts("");
    }

}