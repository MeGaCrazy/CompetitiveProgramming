/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Mar 29 17:36:16 2018
*   @Idea :     Just Sort Points it's obvious that First and Last One That the point that may make line cross by Center of Symmetry
*               and also The Second ,and the one before the last ... and so one Just get the Center and Check if Other Their Center
*               is Same ... :)
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;

struct point{
  int x,y;
  inline bool operator <(point &other){
         if( abs(x-other.x)==0)
                   return y < other.y;
         return x < other.x;
  }        
};
const int N=10005;
point arr[N];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
       int n;
       scanf("%d",&n);
       for(int i=0;i<n;i++){
          scanf("%d %d",&arr[i].x,&arr[i].y);
       }
       sort(arr,arr+n);
       int xx=arr[0].x+arr[n-1].x;
       int yy=arr[0].y+arr[n-1].y;
       bool valid=1;
       for(int i=1;i<n/2;i++){
           int j=n-i-1;
           if(arr[i].x+arr[j].x!=xx||arr[i].y+arr[j].y!=yy){
              valid=0;
              break;
           }
       }
       if(valid){
         printf("yes\n");
       }else {
          printf("no\n");
       }

       
   }



}