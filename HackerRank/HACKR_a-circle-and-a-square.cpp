/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Feb 09 11:55:34 2018
*   @Idea :    1-First For Checking is in circle with a trivial equation of circle (x-c)^2+(y-c)^2<=r*r
*              2-Second For Square ... Well make vector from point1,point3 and get mid point of vector(v1)..then
*                 make get the 2 prependicalr vector and add mid point to them 
*                 Get the length from mid to point 1(Lenmid) now for the two prependicaler vector get their length and 
*                 and the position of point 3 or 4 = Lenmid/lenOfPrenedicaler Vector and then just get the point on vector 
*                 using Parametric equation :)
*                 For Checking if point in square check ccw for all continous point in square and this point if >=0 then it in..
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point &other){
      return point(x-other.x,y-other.y);
  }
  point operator +(point &other){
      return point(x+other.x,y+other.y);
  }
  point operator *(double f){
       return point(x*f,y*f);
  }
  inline bool operator <(point &other){
      return (x<other.x ||(x==other.x && y<other.y));
  }

};
point square[4];
int w,h;
const int N=105;
int arr[N][N];
const double EPS=1e-5;
int dcmp(double x,double y){
    return fabs(x-y)<EPS?0:x>y?1:-1;
}
double length(point v){
      return sqrt((v.x*v.x)+(v.y*v.y));
}

double dis(double x,double y,double xx,double yy){
	return (xx-x)*(xx-x)+(yy-y)*(yy-y);
}

bool InCirc(point &c,double r,double x,double y){
         double di=x-c.x;
         double dj=y-c.y;
         return di*di+dj*dj<=r*r;
}
double norm(point &v){
    return sqrt((v.x*v.x)+(v.y*v.y));
}
double cross(point &v1,point &v2){
   return v1.x*v2.y-v1.y*v2.x;
}
int ccw(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    if(cross(v1,v2)>EPS)return 1;
    if(cross(v1,v2)<-EPS)return -1;
    if(v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
    if(norm(v1) < norm(v2)-EPS)return 1;
    return 0;
}
void BuildSquare(){             // look some how confusing but he is really trivial idea :) 
      point mid=(square[0]+square[1])*0.5;
      double lenmid=length(mid-square[0]);
      point v1=square[1]-square[0];
      point prv1=point(v1.y,-v1.x);
      point prv2=point(-v1.y,v1.x);
      point end1=prv1+mid;
      point end2=prv2+mid;
      point vv1=end1-mid; 
      point vv2=end2-mid;
      double lenprv1=length(vv1);
      double lenprv2=length(vv2);
      double t1=lenmid/lenprv1;
      double t2=lenmid/lenprv2;
      square[2]=(vv1*t1)+mid;
      square[3]=(vv2*t2)+mid;
//      sort(square,square+4);
     swap(square[2],square[1]);
}
bool InSq(double x,double y){
      point f=point(x,y);
      return ccw(square[0],square[1],f)>=0&&ccw(square[1],square[2],f)>=0&&ccw(square[2],square[3],f)>=0&&ccw(square[3],square[0],f)>=0;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
     scanf("%d %d",&w,&h);
     point c;
     scanf("%lf %lf",&c.x,&c.y);
     double r;
     scanf("%lf",&r);
     for(int i=0;i<2;i++){
         scanf("%lf %lf",&square[i].x,&square[i].y);
     }
     BuildSquare();
     for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
           if(InCirc(c,r,(double)j,(double)i)||InSq(j,i))printf("#");
           else printf(".");
        }
        puts("");
     }

}