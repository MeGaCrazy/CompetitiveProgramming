/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Mar 28 18:00:01 2018
*   @Idea :   Get ConvexHull For Each Kingdom then Check if the missile inside this polygon if does add it's area
*            must print \n due not to get WA
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;

struct point{
  int x,y;
  point(int x=0,int y=0):x(x),y(y){}
  point operator -(point &other){
        return point(x-other.x,y-other.y);
  }
  inline bool operator <(point &other){
        if(abs(x-other.x) ==0)
                return y < other.y;
        return x < other.x;        	 
  }

};
const int N=105;
point ans[N<<1];
long long cross(point v1,point v2){
     return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
long long norm(point &v1){
    return 1ll*v1.x*v1.x+1ll*v1.y*v1.y;
}
int ccw(point &a,point &b,point &c){
   point v1=b-a;
   point v2=c-a;
   if(cross(v1,v2) >0)return 1;
   if(cross(v1,v2) < 0)return -1;
   if(v1.x*v2.x <0 || v1.y*v2.y < 0)return -1;
   if(norm(v1) < norm(v2))return 1;
   return 0;

}
bool onpoly(vector<point>&v,point &a){
      int cnt=0;
      for(int i=0;i<(int)v.size()-1;i++){
          point cur=v[i];
          point nxt=v[i+1];
          if(ccw(cur,nxt,a)==0)return 1;
          if(a.y <= cur.y){
               if(a.y > nxt.y && cross(nxt-cur,a-cur)<0)cnt++;
          }else{
             if(a.y <= nxt.y && cross(nxt-cur,a-cur) >0)cnt--;
          }
      }
      return cnt!=0;
}

vector<point>modify(vector<point>&arr){
      sort(arr.begin(),arr.end());
      int st=0,sz=0;
      int n=arr.size();
      for(int i=0;i<n;i++){
         while(sz-st>=2&&cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])<=0)sz--;
         ans[sz++]=arr[i];
      }
      st=--sz;
      for(int i=n-1;i>=0;i--){
         while(sz-st>=2&&cross(ans[sz-1]-ans[sz-2],arr[i]-ans[sz-2])<=0)sz--;
         ans[sz++]=arr[i];
      }
      vector<point>v(ans,ans+sz);
      return v;

}
double get_area(vector<point>&v){
      double ret=0;
      for(int i=0;i<(int)v.size()-1;i++){
         ret+=cross(v[i],v[i+1]);
      }
      return fabs(ret/2.0);
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int n;
     int x,y;
     vector< vector<point> > poly;
     while(scanf("%d",&n),n!=-1){
          vector<point>v;
       for(int i=0;i<n;i++){
          scanf("%d %d",&x,&y);
          v.push_back(point(x,y));
       }
       poly.push_back(v);
     }
     vector<point>ms;
     while(scanf("%d %d",&x,&y)==2){
        ms.push_back(point(x,y));
     }
     vector<vector<point> >npoly;
     for(int i=0;i<(int)poly.size();i++){
         npoly.push_back(modify(poly[i]));
     }
     double f=0;
     for(int i=0;i<npoly.size();i++){
        for(int j=0;j<ms.size();j++){
            if(onpoly(npoly[i],ms[j])){f+=get_area(npoly[i]);break;}
        }
     }
     printf("%.2f\n",f);


}