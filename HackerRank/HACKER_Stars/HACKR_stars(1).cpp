/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Feb 08 10:25:56 2018
*   @Idea :   Just Generate line between two point and Check who is left and who is right for point lay on line 
*             can move line sticky right or left or diagonal that can take one in part and one in another 
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
  int w;
  point(double x=0,double y=0,int w=0):x(x),y(y),w(w){}
  point operator -(point &other){
     return point(x-other.x,y-other.y);
  }
};
const int N=105;
point arr[N];
const double EPS=1e-5;
double cross(point v1,point v2){
    return v1.x*v2.y-v1.y*v2.x;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int n;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
        scanf("%lf %lf %d",&arr[i].x,&arr[i].y,&arr[i].w);
     }
     int ans=-1;
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            point v1=arr[j]-arr[i];
            int l=0,r=0;
            for(int k=0;k<n;k++){
               point v2=arr[k]-arr[i];
               if(cross(v1,v2)>EPS)l+=arr[k].w;
               else if(cross(v1,v2)<-EPS)r+=arr[k].w;
            }
            // whole
            ans=max(ans,min(l+arr[i].w+arr[j].w,r));
            ans=max(ans,min(l,r+arr[i].w+arr[j].w));
            // part
            ans=max(ans,min(l+arr[i].w,r+arr[j].w));
            ans=max(ans,min(l+arr[j].w,r+arr[i].w));
         }
     }
     printf("%d",ans);

}