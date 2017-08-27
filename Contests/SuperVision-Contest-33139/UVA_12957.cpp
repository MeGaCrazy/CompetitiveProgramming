/*
*     Idea : First sort according to bigger y then small x  so now we focus in x only. 
*            now for every coordinate  x we from Right ( if he less than the bigger coordinate x  from right and less then in y (obviously they had sorted :)) 
*           or  from left if he bigger than the minimum coordinate from left then then it can be park :) 
*
*
*/
#include <bits/stdc++.h>
using namespace std;
const int N=3005;
struct node{
   int x,y;
   bool operator <(node f)const {
      if(y>f.y)return y > f.y;
      else if(y==f.y)return x < f.x;
      else  return 0;
   }
};

node arr[N];
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
     int n;
       while(scanf("%d",&n)==1){
           for(int i=0;i<n;i++){
             scanf("%d %d",&arr[i].x,&arr[i].y);
           }
           sort(arr,arr+n);
           int ans=0;
           for(int i=0;i<n;i++){
              int lx=-(1e9),rx=(int)1e9;
               for(int j=i+1;j<n;j++){
                   if(arr[j].x > arr[i].x){
                      if(arr[j].x < rx){
                         ans++;
                         rx=min(rx,arr[j].x);
                      }
                   }else{
                      if(arr[j].x > lx){
                        ans++;
                        lx=max(arr[j].x,lx);
                      }
                   }
               }
           }
           printf("%d\n",ans);
     }
}