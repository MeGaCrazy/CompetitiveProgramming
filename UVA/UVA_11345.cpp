/*
*  target :get max common area in rectangle
*   sol   : get min point from right top corner and max point from left down corner
*           corner case : u should check if point min right corner > max  points left down corner
*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    int t,n,cas=1;
    scanf("%d",&t);
    while(t--){
      scanf("%d",&n);
      int minx=1e9,miny=1e9,maxx=-1e9,maxy=-1e9;
      bool ok=true;
      for(int i=0,x1,y1,x2,y2;i<n;i++){
           scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
          if(ok){
            maxx=max(maxx,x1),maxy=max(maxy,y1);
            minx=min(minx,x2),miny=min(miny,y2);
            if(maxx>=minx||maxy>=miny)ok=false;
           }
      }
      printf("Case %d: %d\n",cas++,ok==false?0:(minx-maxx)*(miny-maxy));
   }
}