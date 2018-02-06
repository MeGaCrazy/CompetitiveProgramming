/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Feb 06 01:58:57 2018
*   @Idea :  Greedy Idea :D Just Sort Point according to x coordinate then take first two point now iterate for the first point 
*            not collinear with both of taken points :) 
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point {
  int x,y,id;
  point (int X=0,int Y=0,int ID=0):x(X),y(Y),id(ID){}
  inline bool operator <(point &other){
      return (x<other.x || ((x==other.x)&&y < other.y)||(x==other.x && y==other.y
               && id < other.id));
  }
  point operator -(point other){
     return point(x-other.x,y-other.y);
  }
};
const int N=1e5+7;
point arr[N];
long long cross(point &v1,point &v2){
 return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
bool isCollinear(point &a,point &b,point &c){
     point v1=b-a;
     point v2=c-a;
     return cross(v1,v2)==0;
}
int main(){
#ifndef ONLINE_JUDGE
//   freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       scanf("%d %d",&arr[i].x,&arr[i].y);
       arr[i].id=i+1;
    }
    sort(arr,arr+n);
    for(int i=2;i<n;i++){
       if(!isCollinear(arr[0],arr[1],arr[i])){
           arr[2]=arr[i];
           break;
       }
    }
    for(int i=0;i<3;i++){
       printf("%d",arr[i].id);
       if(i!=2){
         printf(" ");
       }
    }

}