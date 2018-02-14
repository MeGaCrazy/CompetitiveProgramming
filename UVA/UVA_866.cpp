/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Feb 14 14:52:39 2018
*   @Idea :   Greedy Forumla .. Just if intersect get 2 new segment add 1 for orginial value
* 
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
  bool inline operator ==(point &other){
     return x==other.x&&y==other.y;
  }
  bool inline operator <(point &other){
     return (x < other.x - EPS || (fabs(x -other.x) < EPS && y < other.y -EPS));
  }
  point operator *(double f){
     return point(x*f,y*f);
  }
  point operator +(point other){
     return point(x+other.x,y+other.y);
  }
};
struct seg{
  point a,b;
};
const int N=10005;
seg arr[N];
double norm(point &v){
  return sqrt((v.x*v.x)+(v.y)*(v.y));
}
double cross(point &v1,point &v2){
    return v1.x*v2.y-v1.y*v2.x;
}
int ccw(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    if(cross(v1,v2) > EPS)return 1;
    if(cross(v1,v2) < -EPS)return -1;
    if(v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
    if(norm(v1) < norm(v2) -EPS)return 1;
    return 0;
}
bool Inter(point &a,point &b,point &c,point &d){
    bool f1=(b==a),f2=(c==d);
    if(f1) return ccw(c,d,a)==0;
    if(f2) return ccw(a,b,c)==0;
    return ccw(a,b,c)*ccw(a,b,d)<=0&&
           ccw(c,d,a)*ccw(c,d,b)<=0;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
     while(t--){
       int n;
       scanf("%d",&n);
       for(int i=0;i<n;i++){
          scanf("%lf %lf %lf %lf",&arr[i].a.x,&arr[i].a.y,&arr[i].b.x,&arr[i].b.y);
       }
       int ans=0;
       for(int i=0;i<n;i++){
          int cnt=0;
          for(int j=i+1;j<n;j++){
            if(Inter(arr[i].a,arr[i].b,arr[j].a,arr[j].b)){
                cnt+=2;
               }
          }
          cnt++;
          ans+=cnt;
       }
       printf("%d\n",ans);
       if(t) puts("");
     }



}
