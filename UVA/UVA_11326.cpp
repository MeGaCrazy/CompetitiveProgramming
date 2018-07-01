/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Jun 29 09:56:55 2018
*   @Idea :         WA :)
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const double EPS=1e-10;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point other){
  	return point((fabs(x-other.x) < EPS)?0:x-other.x,(fabs(y-other.y) < EPS)?0:y-other.y);
  }
  point operator *(double f){
  	return point(x*f,y*f);
  }
  point operator +(point other){
  	return point(x+other.x,y+other.y);
  }

};
point square[5];
double length(point v1){
	return sqrt((v1.x)*(v1.x)+(v1.y)*(v1.y));
}

int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
    	double l,w,deg;
    	scanf("%lf %lf %lf",&l,&w,&deg);
      square[0]=point(0,0);
      square[1]=point(l,0);
      square[2]=point(l,w);
      square[3]=point(0,w);
      double ref_deg=sqrt(90*90-deg*deg)*2;
      double ddeg=(90-ref_deg*0.5);
      deg=deg*acos(-1)/180.0;
      double newl=(w/tan(deg))*2;

      double distance=length(square[1]-square[0]);
      int Ratio=floor((distance+0.01)/newl);
      point lastpoint;
      point endpoint;
      if(!(Ratio&1)){
         point v=square[2]-square[3];
	   lastpoint=square[3]+(v*((newl*(double)Ratio)/distance));
	   double lastl=length(square[2]-lastpoint);
	   double neww=tan(ddeg/180.0*acos(-1))*lastl;
	   endpoint=point(square[2].x,square[2].y-neww);
	//   cerr<<endpoint.x<<" "<<endpoint.y<<endl;
      }else{
        point v=square[1]-square[0];
        lastpoint=square[0]+(v*((newl*(double)Ratio)/distance));
        double lastl=length(square[1]-lastpoint);
        double neww=tan(ddeg*acos(-1)/180.0)*lastl;
        endpoint=point(square[1].x,square[1].y+neww);
	//  cout<<lastl<<" "<<neww<<" "<<lastpoint.x<<" "<<lastpoint.y<<endl;
      }
      double hype=w/sin(deg);
     	double A=(hype*2.0*Ratio)+length(endpoint-lastpoint);
     	double B=length(endpoint-square[0]);
     	printf("%.3f\n",A/B);
    }
}