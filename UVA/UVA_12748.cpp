/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Feb 03 10:29:39 2018
*   @Idea :    Just Check if within Area Using Circle equation (a-c)^2+(b-c)^2<=r*r
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
 int x,y,r;
};
const int N=105;
point arr[N];
int dis(int x,int y,int xx,int yy){
   return (x-xx)*(x-xx)+(y-yy)*(y-yy);
}
bool Can(int n,int a,int b){
    for(int i=0;i<n;i++){
        int r=arr[i].r;
        if(dis(a,b,arr[i].x,arr[i].y)<=r*r){
           return 1;
        }
    }
    return  0;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
  // freopen("out","w",stdout);
#endif 
     int t;
     scanf("%d",&t);
     int Cas=1;
     while(t--){
         int n,y;
         printf("Case %d:\n",Cas++);
         scanf("%d %d",&n,&y);
         for(int i=0;i<n;i++){
            scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].r);
         }
         for(int i=0;i<y;i++){
             int x,y;
             scanf("%d %d",&x,&y);
             if(Can(n,x,y)){
                puts("Yes");
             }else{
                puts("No");
             }
         }

     
     }



}