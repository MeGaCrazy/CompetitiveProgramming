/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Feb 08 16:19:43 2018
*   @Idea :   Just Get Minimum Enclosing Circle and compare it's Rad with given radius
*
*
*
*
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

};
const int N=105;
point arr[N];
const double EPS=1e-6;
point r[5];
point cen;
double R;
int dcmp(double x,double y){
  return fabs(x-y)<EPS?0:x>y?1:-1;
}

double length(point a){
   return sqrt((a.x*a.x)+(a.y*a.y));
}
double cross(point &v1,point &v2){
   return v1.x*v2.y-v1.y*v2.x;
}
int Inter(point &a,point &b,point &c,point &d,point &ret){
     point u=b-a;
     point v=d-c;
     point w=a-c;
     double f=cross(u,v);
     double t1=cross(v,w)/f;
     double t2=cross(u,w)/f;
   //  cerr<<t1<<" "<<t2<<endl;
   if(f==0){
     return 0;
   }
  //   if(dcmp(t1,0)==-1||dcmp(t1,1)==1||dcmp(t2,0)==-1||dcmp(t2,1)==1)
  //    return 0;

     ret=u*t1+a;

}
pair<point,double>findCirc(point &a,point &b,point &c){
     point v1=b-a;
     point v2=c-a;
     point mid1=(b+a)*0.5;
     point mid2=(c+a)*0.5;
     point prv1=point(v1.y,-v1.x);
     point prv2=point(v2.y,-v2.x);
     point end1=prv1+mid1;
     point end2=prv2+mid2;
     point ret;
     Inter(mid1,end1,mid2,end2,ret);
     return make_pair(ret,length(a-ret));
}
void MEC(int n,int m){
   if(n==0&&m==2){
      cen=r[0]+r[1];
      cen=cen*0.5;
      R=length(r[0]-cen);
   }else if(m==3){
      pair<point,double>circ=findCirc(r[0],r[1],r[2]);
      cen=circ.first;
      R=circ.second;
   }else if(n==0){
      cen=r[0];
      R=0;
   }else{
      MEC(n-1,m);
      if(dcmp(length(arr[n-1]-cen),R)==1){
         r[m]=arr[n-1];
         MEC(n-1,m+1);
      }
   }
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int n;
    while(scanf("%d",&n),n){
       for(int i=0;i<n;i++){
         scanf("%lf %lf",&arr[i].x,&arr[i].y);
       }
       double rad;
       cen=point();
       memset(r,0,sizeof(r));
       R=0;
       scanf("%lf",&rad);
       MEC(n,0);
       if(dcmp(R,rad)!=1 ){
         puts("The polygon can be packed in the circle.");
       }else{
          puts("There is no way of packing that polygon.");
       }
    }



}