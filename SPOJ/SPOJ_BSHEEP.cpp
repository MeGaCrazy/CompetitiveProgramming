/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Mar 27 18:38:57 2018
*   @Idea :   Simple ConvexHull Problem But Tricky Output
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
        if(fabs(x-other.x) < EPS){
            return y < other.y -EPS;
        }
        return x < other.x -EPS;
  }

};
const int N=100005;

pair<int,point>ans[N<<1],arr[N];
double cross(point v1,point v2){
	return v1.x*v2.y-v1.y*v2.x;
}
double length(point &v1,point &v2){
  return sqrt((v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y));

}
inline bool cmp(pair<int,point>&a,pair<int,point>&other){
         if(fabs(a.second.y-other.second.y) < EPS){
            return a.second.x < other.second.x -EPS;
          }
        return a.second.y < other.second.y -EPS;
}
vector<pair<int,point> >modify(int n){
     sort(arr,arr+n,cmp);
     int st=0,sz=0;
     for(int i=0;i<n;i++){
        while(sz-st>=2 && cross(ans[sz-1].second-ans[sz-2].second,arr[i].second-ans[sz-2].second)<=0)sz--;
        ans[sz++]=arr[i];
     }
     st=--sz;
     for(int i=n-1;i>=0;i--){
        while(sz-st>=2 && cross(ans[sz-1].second-ans[sz-2].second,arr[i].second-ans[sz-2].second)<=0)sz--;
        ans[sz++]=arr[i];
     }
     vector<pair<int,point> >v(ans,ans+sz);
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
        set<pair<int,int> >s;
        int j=0;
        for(int i=0;i<n;i++){
           double x,y;
           scanf("%lf %lf",&x,&y);
           if(s.count(make_pair(x,y)))continue;
           s.insert(make_pair(x,y));
           arr[j++]=make_pair(i+1,point(x,y));
        }
        n=j;
        vector<pair<int,point> >ret=modify(n);
        double len=0;
        for(int i=0;i<(int)ret.size()-1;i++){
           len+=length(ret[i].second,ret[i+1].second);
        }
        printf("%.2f\n",len);
        for(int i=0;i<(int)ret.size()-1;i++){
           if(i){printf(" ");}
           printf("%d",ret[i].first);
        }
        if(ret.size()==1){
          printf("%d",ret[0].first);
        }
        printf("\n");
        if(t) puts("");
     }




}