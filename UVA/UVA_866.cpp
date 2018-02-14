/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Feb 14 14:52:39 2018
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
int ff[N];
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
set<pair<pair<int,int> ,pair<int,int> > >s;
bool Inter(point &a,point &b,point &c,point &d){
    bool f1=(b==a),f2=(c==d);
    if(f1) return ccw(c,d,a)==0;
    if(f2) return ccw(a,b,c)==0;
    return ccw(a,b,c)*ccw(a,b,d)<=0&&
           ccw(c,d,a)*ccw(c,d,b)<=0;
}
double dot(point &v1,point &v2){
  return v1.x*v2.x+v1.y*v2.y;
}
bool Onseg(point a,point b,point c){
    point v1=a-c;
    point v2=b-c;
    return cross(v1,v2)==0 && dot(v1,v2) <= 0;
}
bool Edit(point &a,point &b){
   for(auto x:s){
      if(Onseg(point(x.first.first,x.first.second),point(x.second.first,x.second.second),a)
        && Onseg(point(x.first.first,x.first.second),point(x.second.first,x.second.second),b)
      )
      s.erase(x);
      return 0;
   }
   return 1;
}
void getInter(point &a,point &b,point &c,point &d){
  point u=b-a;
  point v=d-c;
  point w=a-c;

  if(cross(u,v)==0)return;
  double t=cross(v,w)/cross(u,v);
  point ret=u*t+a;
  point f[2];
  f[0]=a;
  f[1]=ret;
  sort(f,f+2);
  Edit(f[0],f[1]);
  s.insert(make_pair(make_pair(f[0].x,f[0].y),make_pair(f[1].x,f[1].y)));

  f[0]=b;
  f[1]=ret;
  sort(f,f+2);
  Edit(f[0],f[1]);
  s.insert(make_pair(make_pair(f[0].x,f[0].y),make_pair(f[1].x,f[1].y)));  

  f[0]=c;
  f[1]=ret;
  Edit(f[0],f[1]);
  s.insert(make_pair(make_pair(f[0].x,f[0].y),make_pair(f[1].x,f[1].y))); 

  f[0]=d;
  f[1]=ret;
  sort(f,f+2);
  Edit(f[0],f[1]);
  s.insert(make_pair(make_pair(f[0].x,f[0].y),make_pair(f[1].x,f[1].y)));  
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
     while(t--){
       s.clear();
       int n;
       scanf("%d",&n);
       memset(ff,0,sizeof(ff));
       for(int i=0;i<n;i++){
          scanf("%lf %lf %lf %lf",&arr[i].a.x,&arr[i].a.y,&arr[i].b.x,&arr[i].b.y);
       }
       int ans=0;
       for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            if(Inter(arr[i].a,arr[i].b,arr[j].a,arr[j].b)){
                  getInter(arr[i].a,arr[i].b,arr[j].a,arr[j].b);
                  ff[i]=1;
                  ff[j]=1;
            	}
          }
       }
       for(int i=0;i<n;i++){
         if(!ff[i])ans++;
       }
       printf("%d\n",s.size()+ans);
       if(t) puts("");

     }



}