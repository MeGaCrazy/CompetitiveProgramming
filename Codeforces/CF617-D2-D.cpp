/**
*   @Author : MeGaCrazy
*   @InitTime : Sun Dec 03 00:54:53 2017
*   @Idea :  if all same in x axis or y axis print 1 else if all diferrent print 3 
*            Case 2 if the point is between the the two point and equal in x or y print 2 :) 
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
bool Check(int ax, int ay,int bx,int by,int cx,int cy){
       if( min(bx,cx) <= ax && ax <= max(bx,cx) && min(by,cy) <= ay && ay <= max(by,cy)){
           return ax==bx||ax==cx||ay==cy||ay==by;
       }
       return 0;

}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
  // freopen("out","w",stdout);
#endif
   int ax,ay,bx,by,cx,cy;
   scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
   if((ax==bx && bx==cx)||(ay==by&&cy==by)){
       puts("1");
   }else if( Check(ax,ay,bx,by,cx,cy)||Check(bx,by,cx,cy,ax,ay)||Check(cx,cy,ax,ay,bx,by)){
         puts("2");
   }else 
      puts("3");




}