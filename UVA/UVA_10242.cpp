/*
* target : get fourth point of pallelogram
* sol : determine the endpoint of 2 vectors u,v and get v'=u+v all need for get new points forumla newx=(notendpointx1+notendpointx2)-endpoint 
*       corner case : u must subtract forumla from  endpoint that can be not in origin
*
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
   double x1,x2,x3,x4,y1,y2,y3,y4;
   while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF){
      double ansx,ansy;
       if(x1==x3&&y1==y3){
           ansx=(x2+x4)-x3;
           ansy=(y2+y4)-y3;
        }
       else if(x1==x4&&y1==y4){
           ansx=(x2+x3)-x1;
           ansy=(y2+y3)-y1;
       }
      else if(x2==x3&&y2==y3){
            ansx=(x1+x4)-x3;
            ansy=(y1+y4)-y3;
       }
      else {
          ansx=(x1+x3)-x4;
          ansy=(y1+y3)-y4;
       }
       printf("%.3f %.3f\n",ansx,ansy);
   }

}