/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Feb 10 13:51:30 2018
*   @Idea :
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct circ{
  double x,y,r;
  circ(double x=0,double y=0,double r=0):x(x),y(y),r(r){}
  circ operator -(circ &other){
       return circ(x-other.x,y-other.y);
  }
};
const double pi=acos(-1);
double length(circ &v1){
  	return sqrt((v1.x*v1.x)+(v1.y*v1.y));
}
double dis(circ &a,circ &b){
    return sqrt((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y));
}
double cross(circ &v1,circ &v2){
     return v1.x*v2.y-v1.y*v2.x;
}
double GetArea(circ &a,circ &b,circ &c){
     circ v1=b-a;
     circ v2=c-a;
     return (cross(v1,v2)/2);
}
double arcArea(circ &a,circ &b,circ &c){
   circ v1=b-a;
   circ v2=c-a;
   double theta=asin(cross(v1,v2)/(length(v1)*(length(v2))));
   theta = (theta /pi)*180;
   return ((theta / 360 )*(pi*a.r*a.r));

}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    while(n--){
       double r1,r2,r3;
       scanf("%lf %lf %lf",&r1,&r2,&r3);
       circ a(0,0,r1);
       circ c(r1+r3,0,r3);
       double d1=r1+r2;
       double d2=r1+r3;
       double d3=r3+r2;
       double x=-(((d3*d3)-(d1*d1)-(d2*d2))/(-2*d2));
       double y=sqrt((d1*d1)-(x*x));
      // cerr<<" # "<<(x-d2)*(x-d2)<<"  -> "<<(d3*d3) <<endl;
      // cerr<<"1  "<<sqrt((d3*d3)-((x-d2)*(x-d2)))<<endl;
      // cerr<<" 2 "<<sqrt((d1*d1)-(x*x))<<endl;
       circ b(x,y,r2);
       cerr<<"hoi "<<dis(b,c)<<" "<<d3<<endl;
       double totalArea=GetArea(a,b,c);
       double arcAreaA=arcArea(a,b,c);
       double arcAreaB=arcArea(b,a,c);
       double arcAreaC=arcArea(c,a,b);
       printf("%lf\n",totalArea-(arcAreaA+arcAreaB+arcAreaC));
    }

}