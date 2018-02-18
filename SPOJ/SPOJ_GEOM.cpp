/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Feb 17 15:46:24 2018
*   @Idea :    Just Get the point in line By Using Prependicular vector and subtract from other point
*              and Check if the point on  all lines  
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;



const double EPS=1e-5;
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
     return (x  < other.x-EPS || (fabs(x-other.x) <EPS && y < other.y -EPS));
 }
 inline bool operator ==(point &other){
     return fabs(x-other.x)<EPS&&fabs(y-other.y)<EPS;
 }
};
point pt[4];
struct line{
  point a,b;
  line(point a=point(),point b=point()):a(a),b(b){}
};
line l[4];
double Abs(point &v1){
   return (v1.x*v1.x)+(v1.y*v1.y);
}
double cross(point &v1,point &v2){
  return  v1.x*v2.y-v1.y*v2.x;
}
double dot(point &v1,point &v2){
  return v1.x*v2.x+v1.y*v2.y;
}
pair<int,point> Inter(point &a,point &b,point &c,point &d){
      point u=b-a;
      point v=d-c;
      point w=a-c;
      double down=cross(u,v);
      if(down==0)return make_pair(0,point());
      double t1=cross(v,w)/down;
      if(isnan(t1)||isinf(t1))return make_pair(0,point());
      point ret=u*t1+a;
      return make_pair(1,ret);
}

line solve(point &a,point &b,point &p){
    /*
    point v=p-b;
    point w=a-b;
    double t=dot(v,w)/Abs(v);
    point ret=(v*t)+b;
    return line(ret,a);
    */
    point v=p-b;
    point ret=point(a.x-v.y,a.y+v.x);
    return line(a,ret);
}
int dx[]={1,-1,-1,1};
int dy[]={1,-1,1,-1};
void modify(point &cen,double r){
  r/=2.0;
  for(int i=0;i<4;i++){
      double nx=cen.x+(dx[i]*r),ny=cen.y+(dy[i]*r);
      pt[i]=point(nx,ny);
  }
  sort(pt,pt+4);
  swap(pt[2],pt[3]);
}
bool Online(point &a,point &b,point &c){
     if(a==b)return c==a;
     point v1=c-a;
     point v2=b-a;
     return cross(v2,v1) <EPS;
}

int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    point cen;
    scanf("%lf %lf",&cen.x,&cen.y);
    double r;
    scanf("%lf",&r);
    point p;
    scanf("%lf %lf",&p.x,&p.y);
    modify(cen,r);           
    for(int i=0;i<4;i++){
     l[i]=solve(pt[i],pt[(i+1)%4],p);
    }
    pair<int,point> ans=make_pair(0,point());
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
         if(i==j)continue;
         pair<int,point>ret=Inter(l[i].a,l[i].b,l[j].a,l[j].b);
         if(ret.first==1){
            ans=ret;
         }
       } 																
    }
    if(ans.first==0){
       printf("NO");
       return 0;
    }
    for(int i=0;i<4;i++){
       if(!Online(l[i].a,l[i].b,ans.second)){
         printf("NO");
         return 0;
       }
    }
    printf("YES\n%.1f %.1f",ans.second.x,ans.second.y);

}