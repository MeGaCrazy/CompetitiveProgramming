/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Mar 26 17:55:52 2018
*   @Idea :    Just Get ConvexHull =D 
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;

const double EPS=1e-9;
const int N=1e6;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point &other){
     return point(x-other.x,y-other.y);
  }
  inline bool operator <(point &other){
       if(fabs(x-other.x) < EPS){
           return y < other.y -EPS;
       }
       return x < other.x -EPS;
  }
};
point ans[N];
double cross(point v1,point v2){
   return v1.x*v2.y-v1.y*v2.x;
}
vector<point>arr;

vector<point>modify(int n){
       sort(arr.begin(),arr.end());
       int st=0,sz=0;
       for(int i=0;i<n;i++){
         while(sz-st>=2 && cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])<=0)sz--;
         ans[sz++]=arr[i];
       }	
       st=--sz;
       for(int i=n-1;i>=0;i--){
          while(sz-st>=2&& cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2]) <=0)sz--;
          ans[sz++]=arr[i];
       }
       if(sz<0)sz=0;
       vector<point>ret(ans,ans+sz);
       return ret;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif 
    double x,y;
    string s;
    while(getline(cin,s)){
       char c;
        arr.clear();
       stringstream in(s);
       while(in>>c>>x>>c>>y>>c){
       arr.push_back(point(x,y));
       }
    
      vector<point>ret=modify(arr.size());
      for(int i=0;i<(int)ret.size();i++){
        if(i){
          printf(" ");
        }
        printf("(%g,%g)",ret[i].x,ret[i].y);
     }
      puts("");
   }

}