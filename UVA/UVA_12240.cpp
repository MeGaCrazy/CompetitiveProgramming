/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Feb 01 01:27:01 2018
*   @Idea :  Just Try Every 3 Point to make circle and get see how many point lie on circumference
*         
*         CornerCase : if n= 2 or 1 point the answer is n
*
*        
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  double x,y;
  point():x(0),y(0){}
  point(double a,double b):x(a),y(b){}
  point operator -(point a){
      return point(x-a.x,y-a.y);
  }
  point operator +(point a){
     return point(x+a.x,y+a.y);
  }
  point operator *(double f){
        return point (x*f,y*f);
  }
};
const int N=105;
const double EPS=1e-8;
int dcmp(double x,double y){
   return fabs(x-y)<EPS?0:x>y?1:-1;
}
point arr[N];
     int n;
double cross(point a,point b){
     return a.x*b.y-a.y*b.x;
}
double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int interSeg(point a,point b,point c,point d,point &ret){
   point u=b-a;
   point v=d-c;
   point w=a-c;
   double f=cross(u,v);
   if(f==0){
    return -1;
   }
   double f1=cross(v,w);
   double f2=cross(u,w);
   double t1=f1/f;
   ret=a+(b-a)*t1;
   return 1;
}
pair<double,point> findCircle(point a,point b,point c){
         point v1=b-a;
         point v2=c-a;
         point mid1=(b+a)*.5;
         point mid2=(c+a)*.5;
         point prv1=point(v1.y,-v1.x);
         point prv2=point(v2.y,-v2.x);
         point end1=prv1+mid1;
         point end2=prv2+mid2;
         point center;
         interSeg(mid1,end1,mid2,end2,center);
         return make_pair(dis(center,a),center);
}                                                
int cnt(double rad,point center){
    int ret=0;
    for(int i=0;i<n;i++){
         if(dcmp(dis(center,arr[i]),rad)==0)ret++;
    }
    return ret;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&arr[i].x,&arr[i].y);
        }
        int ans=min(n,2);
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               for(int k=j+1;k<n;k++){
                  pair<double,point>ret=findCircle(arr[i],arr[j],arr[k]);
                  ans=max(ans,cnt(ret.first,ret.second));
               }
           }
        }
       printf("%d\n",ans);
     }
}