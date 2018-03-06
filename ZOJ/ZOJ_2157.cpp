/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Mar 03 19:53:27 2018
*   @Idea :   First Of all The number of point must be even to connect wir(line) must there's a line 
*             The Problem Means calculate the polygon perimeter that the deeper meaning..
*             The Shortest Wire is the Wire Connect The Most Closest 2 points :) 
*             For That Sort by x axis and get the sum of difference in y between two point it same like that 
*                    *
*                    |       *
*               *    |       |
*               |    *       |
*               |            |
*               *            *
*
*             and then sort by y and add the sum of difference in x between two point
*
*
*
*                *------*
*             *\ |      |
*             | \|      |       :) That The Beauty of the Question he needs to calcualte the Perimeter :) 
*             |  *      |
*             *---------*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct point{
  int x,y;
};        
point arr[N];
bool cmp1(point &a,point &b){
     if(a.x==b.x)
           return a.y < b.y;
     return a.x < b.x;
}
bool cmp2(point &a,point &b){
    if(a.y==b.y)
           return a.x < b.x;
    return a.y < b.y;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int n;

    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%d %d",&arr[i].x,&arr[i].y);
        }
        int ans=0;
        sort(arr,arr+n,cmp1);
        for(int i=0;i<n;i+=2){
          ans+=(arr[i+1].y-arr[i].y);
        }
        sort(arr,arr+n,cmp2);
        for(int i=0;i<n;i+=2){
           ans+=(arr[i+1].x-arr[i].x);
        }
        printf("The length of the fence will be %d units.\n",ans);
    }

}