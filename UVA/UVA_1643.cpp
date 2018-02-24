/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Feb 24 14:07:45 2018
*   @Idea :  First of all The Image in the problem not the optimal solution...
*            SoOo what's the optimal : is to make  every begining of square  like this 
*            // https://photos.app.goo.gl/E2ZbXDbRwdJE8V1I2 
*
*            the third side of the triangle is the sum of diagonals of squares and the shaded  area is
*            The area that should not included in ans ..For illustration 
*            //https://photos.app.goo.gl/TOvB9Zt0jfC9k6Kq1
*
*            now make a line it's begining is point A and it's  end and is the sum of end point of squares and 
*            Get the intersection point in line  (0,0) to B ...
*
*            Now easily get the area triangle  using Cross /2.0 =D 
*            Now To get the final area you need to know the "side A to Intersection point" is average length to needed that is
*            Sum of diagonals and then from low = .5 * width * height ,,, if width increased by say 1.5 Then height must increase the same :) 
*
*            So Get the average of increasing side and mutliply by the Calculated Area
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point other){
    return point(x-other.x,y-other.y);
  }
  point operator +(point other){
    return point(x+other.x,y+other.y);
  }
  point operator *(double f){
    return point(x*f,y*f);
  }

};

double cross(point &v1,point &v2){
   return v1.x*v2.y-v1.y*v2.x;
}
double length(point v){
   return sqrt((v.x*v.x)+(v.y*v.y));
}
point Inter(point a,point b,point c,point d){
    point u=b-a;
    point v=d-c;
    point w=a-c;
    double t=cross(v,w)/cross(u,v);
    point ret=u*t+a;
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int n;
     while(scanf("%d",&n),n){
       point a,b;
       scanf("%lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y);
       double out=0;
       double len=0;
       double ans=0;
       point f;
       for(int i=0;i<n;i++){
           double l;
           scanf("%lf",&l);
           len+=l;              // Sum Of  Diagonals 
           f=f+point(l,-l);     // Getting the end point result from summing squaring as discreaped
           out+=(l*l)/2.0;     // Shaded Area "Out Area"
       }
       len*=sqrt(2);
       b=Inter(a,f+a,point(),b);
       ans+=fabs(cross(a,b))/2.0;
       ans*=(len/length(a-b))*(len/length(a-b));
       printf("%.3f\n",ans-out);
     }
}