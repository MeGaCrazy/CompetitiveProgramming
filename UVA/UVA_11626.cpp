/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Mar 28 10:07:31 2018
*   @Idea :   Usual ConvexHull Problem But With Nice Trick Consider Collinear point :) 
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
    inline bool operator <(point &other){
            if(fabs(x-other.x) <EPS)
                  return y < other.y -EPS;
            return x < other.x -EPS;
    }


};
const int N=1e5+7;
point ans[N<<1];
double cross(point v1,point v2){
   return v1.x*v2.y-v1.y*v2.x;
}

vector<point>modify(vector<point>&arr){
      int n=arr.size();
      sort(arr.begin(),arr.end());
      int st=0,sz=0;
      for(int i=0;i<n;i++){
          while(sz-st >=2 && cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])<0)sz--;
          ans[sz++]=arr[i];
      }
      st=--sz;
      for(int i=n-1;i>=0;i--){
         while(sz-st>=2 && cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])<0)sz--;
         ans[sz++]=arr[i];
      }
      vector<point>v(ans,ans+sz);
      return v;
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
       vector<point>arr;
       for(int i=0;i<n;i++){
        char c;
        double x,y;
        scanf("%lf %lf %c",&x,&y,&c);
        if(c=='N')continue;
        arr.push_back(point(x,y));
       }
       vector<point>ret=modify(arr);
       printf("%d\n",(int)ret.size()-1);
       for(int i=0;i<ret.size()-1;i++){
          printf("%lld %lld\n",(long long)ret[i].x,(long long)ret[i].y);
       }
    
    
    }



}