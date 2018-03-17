/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Mar 17 02:29:53 2018
*   @Idea :   Get the Intersection points and point that on contains by each other that usual using Winding Number and usual 
*             Intersect check..
*             Let's Go For New Idea : how I can construct polygon clockwise and remove duplicate points .. :) 
*             Iterate for each point if cross product between it and the two point behind it > 0 then it clockwise and add to answer
*             and then iterate from end make same Check ...
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const double EPS=1e-6;
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
  inline bool operator ==(point &other){
    return fabs(x-other.x) < EPS&& fabs(y-other.y) <EPS;
  }
  inline bool operator <(point &other){
     if(fabs(x-other.x) <EPS)
           return y < other.y -EPS;
     return x < other.x - EPS;
   }
};



double norm(point &v1){
  return sqrt((v1.x*v1.x)+(v1.y*v1.y));
}
double cross(point v1,point v2){
   return v1.x*v2.y-v1.y*v2.x;
}
int ccw(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    if(cross(v1,v2) >EPS)return 1;
    if(cross(v1,v2) < -EPS)return -1;
    if(v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
    if(norm(v1) < norm(v2) -EPS)return 1;
    return 0;
}

pair<bool,point> InterSeg(point &a,point &b,point &c,point &d){ 
  point u=b-a;
  point v=d-c;
  point w=a-c;
  double t1=cross(v,w)/cross(u,v);
  if(isnan(t1) ||  isinf(t1))return make_pair(0,point());
  point ret=(u*t1)+a;
  return make_pair(1,ret);
}

bool Inter(point &a,point &b,point &c,point &d){
  bool f1=(b==a),f2=(c==d);
  if(f1 && f2) return c==a;
  if(f1) return ccw(c,d,a)==0;
  if(f2) return ccw(a,b,c)==0;

  return ccw(a,b,c)*ccw(a,b,d)<=0&&
         ccw(c,d,a)*ccw(c,d,b)<=0;
}

bool onpoly(vector<point>&v,point &u){
     int cnt=0;
     for(int i=0;i<(int)v.size()-1;i++){
         point cur=v[i];
         point nxt=v[i+1];
         if(ccw(cur,nxt,u)==0)return 0;
         point v1=nxt-cur;
         point v2=u-cur;
         
         if(cur.y <= u.y){
             if(nxt.y > u.y && cross(v1,v2) > EPS)cnt++;
         }else{
             if(nxt.y <= u.y && cross(v1,v2) < -EPS)cnt--;
         }
     }
     return cnt!=0;
}
double getarea(vector<point>&v){
    double ret=0;
    for(int i=0;i<(int)v.size()-1;i++){
       ret+=cross(v[i],v[i+1]);
    }
    ret/=2.0;
    return fabs(ret);
}
vector<point> modify(vector<point>&v){
     vector<point>ret(1000,point());
     sort(v.begin(),v.end());
     int sz=0,st=0;
     for(int i=0;i<(int)v.size();i++){
         while(sz-st >=2 &&(cross(ret[sz-1]-ret[sz-2],v[i]-ret[sz-2])<=0))sz--;
         ret[sz++]=v[i];
     }
     st=--sz;
     for(int i=v.size()-1;i>=0;i--){
         while(sz-st >=2 && (cross(ret[sz-1]-ret[sz-2],v[i]-ret[sz-2])<=0))sz--;
         ret[sz++]=v[i];
     }
     vector<point>r;
     for(int i=0;i<sz;i++){
        r.push_back(ret[i]);
     }
     
     return r;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   freopen("out","w",stdout);
#endif
     int n;
     while(scanf("%d",&n),n){
          double x,y; 
          vector<point>poly1,poly2,ans;
         for(int i=0;i<n;i++){
          scanf("%lf %lf",&x,&y);
           poly1.push_back(point(x,y));
         }
         int m;
         scanf("%d",&m);
         for(int i=0;i<m;i++){
           scanf("%lf %lf",&x,&y);
           poly2.push_back(point(x,y));
         }
         reverse(poly1.begin(),poly1.end());
         reverse(poly2.begin(),poly2.end());
         poly1.push_back(poly1[0]);
         poly2.push_back(poly2[0]);
         // contain
         for(int i=0;i<(int)poly1.size()-1;i++){
            if(onpoly(poly2,poly1[i])){
               ans.push_back(poly1[i]);
            }
         }
         for(int j=0;j<(int)poly2.size()-1;j++){
            if(onpoly(poly1,poly2[j])){
             ans.push_back(poly2[j]);
            }
         }
         // Inter
         for(int i=0;i<(int)poly1.size()-1;i++){
             for(int j=0;j<(int)poly2.size()-1;j++){
                  if(Inter(poly1[i],poly1[i+1],poly2[j],poly2[j+1])){
                      pair<bool,point>r=InterSeg(poly1[i],poly1[i+1],poly2[j],poly2[j+1]);
                      if(r.first==0)continue;
                      ans.push_back(r.second);
                  }
             }
         }

         vector<point>ret=modify(ans);         
         double f=getarea(poly1)+getarea(poly2)-2*getarea(ret);
         printf("%8.2f",f);
     }
     puts("");
}