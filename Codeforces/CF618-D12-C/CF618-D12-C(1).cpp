/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Feb 06 03:18:32 2018
*   @Idea :   another Solution , Build triangle with first 3 point and if point inside the triangle make it one of vertiex of triangle :)
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct point{
  int x,y;
  point(int x=0,int y=0):x(x),y(y){}
  point operator -(point &other){
     return point(x-other.x,y-other.y);
  }

};
long long cross(point &v1,point &v2){
   return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
long long ccw(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    return cross(v1,v2);
}
point arr[N];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
  // freopen("out","w",stdout);
#endif
     int n;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i].x,&arr[i].y);
     }
     int a=0,b=1,c=2;
     int f=0;
     for(int i=2;i<n;i++){
         if(ccw(arr[a],arr[b],arr[i])!=0){
           f=i;
           break;
         }
     }
     c=f;
     if(ccw(arr[a],arr[b],arr[c])<0)swap(b,c);
     for(int i=2;i<n;i++){
         if(i==f)continue;
         if(ccw(arr[a],arr[b],arr[i])>=0&&ccw(arr[b],arr[c],arr[i])>=0&&ccw(arr[c],arr[a],arr[i])>=0){
            if(ccw(arr[a],arr[b],arr[i])!=0)c=i;
            else if(ccw(arr[b],arr[c],arr[i])!=0)a=i;
            else if(ccw(arr[c],arr[a],arr[i])!=0)b=i;
         }
     }
     printf("%d %d %d",a+1,b+1,c+1);
}