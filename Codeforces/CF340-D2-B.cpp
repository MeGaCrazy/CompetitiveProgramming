/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Apr 02 19:47:43 2018
*   @Idea :    Make Line like diagonal and try to get the maximum Triangle area above this line and maxium under using cross product
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
  int x,y;
  point(int x=0,int y=0):x(x),y(y){}
  point operator -(point &other){
      return point(x-other.x,y-other.y);
  }
};
const int N=305;
point arr[N];
long long cross(point v1,point v2){
    return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int n;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
         scanf("%d %d",&arr[i].x,&arr[i].y);
     }
     long long ans=0;
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
              long long Max=-1e18,Min=1e18;
            for(int k=0;k<n;k++){
               if(i==j||j==k||k==i)continue;
               point &a=arr[i];
               point &b=arr[j];
               point &c=arr[k];
               long long tarea=cross(b-a,c-a);
               if(tarea < Min){
                 Min=tarea;
               }
               if(tarea > Max){
                 Max=tarea;
               }
               if(abs(Max-Min) > ans){
                ans=abs(Max-Min);
               }
            }
        }
     }
     printf("%.8f\n",1.0*ans/2.0);
}