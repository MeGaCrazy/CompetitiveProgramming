/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Feb 05 06:05:21 2018
*   @Idea :   Just Greedy idea get the  smallest x,z,y and maximum x,y,z intersect with all cubes 
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct cube{
  int x,y,z;
  cube():x(0),y(0),z(0){}
};
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
  // freopen("out","w",stdout);
#endif
    int n;
    while(scanf("%d",&n),n){
        cube lo,hi;
        int x,y,z,d;
        scanf("%d %d %d %d",&x,&y,&z,&d);
        lo.x=x,lo.y=y,lo.z=z;
        hi.x=x+d,hi.y=y+d,hi.z=z+d;
        for(int i=1;i<n;i++){
          scanf("%d %d %d %d",&x,&y,&z,&d);
          lo.x=max(lo.x,x);
          lo.y=max(lo.y,y);
          lo.z=max(lo.z,z);
          x+=d;
          y+=d;
          z+=d;
          hi.x=min(hi.x,x);
          hi.y=min(hi.y,y);
          hi.z=min(hi.z,z);
        }
        printf("%d\n",max(0,(hi.x-lo.x)*(hi.y-lo.y)*(hi.z-lo.z)));
    }

}