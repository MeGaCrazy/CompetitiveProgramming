/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Feb 03 11:45:00 2018
*   @Idea :  The problem ask if the circle is intersect with another
*            The circle dosen't intersect in 3 condition
*            1- They distance between their center(dist) >= Sum of their radius 
*            2- if contain the other ring
*            3- or the ring contain it 
*            how to check it easily  
*                                 (2) dist+ radiusOfCurCircle <= radius of inner circle of other ring
*                                 (3) dist + radius of outter circle of other ring <= radius radius of curCircle
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct circ{
 int x,y,r;
};
circ arr[5];
double dis(int x,int y,int xx,int yy){
   return (x-xx)*(x-xx)+(y-yy)*(y-yy);
}
bool inter(int a,int b){
   double dist=sqrt(dis(arr[a].x,arr[a].y,arr[b].x,arr[b].y));
   if(arr[a].r+arr[b+1].r <= dist)return 0;
   if(arr[a].r+dist <= arr[b].r) return 0;
   if(arr[b+1].r+dist<=arr[a].r)return 0;
   return 1;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
     for(int i=1;i<=4;i+=2){
        scanf("%d %d %d %d",&arr[i].x,&arr[i].y,&arr[i].r,&arr[i+1].r);
        arr[i+1].x=arr[i].x,arr[i+1].y=arr[i].y;
     }
     int f[5]={0,1,1,1,1};
     for(int i=1;i<=4;i++){
         for(int j=1;j<=3;j+=2){
             if(i!=j&&inter(i,j)){
               f[i]=0;
               break;
             }
         }
     }
     printf("%d",f[1]+f[2]+f[3]+f[4]);
}