/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Mar 28 10:44:44 2018
*   @Idea :   Get The Convex Hull and then Get the ConvexHull for Inner Points and repeat untill <= 2 points remain
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
  int x,y;
  point(int x=0,int y=0):x(x),y(y){}
  point operator -(point &other){
       return point(x-other.x,y-other.y);
  }
  inline bool operator <(point &other){
        if(abs(x-other.x)==0){
             return y < other.y;
        }
        return x < other.x;
  }

};
const int  N=4005;
bool vis[N];
point arr[N];
pair<int,point> ans[N<<1];                              
long long cross(point v1,point v2){
    return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
int n;
int modify(){
        int sz=0,st=0;
        for(int i=0;i<n;i++){
             if(vis[i])continue;
             while(sz-st>=2 && cross(ans[sz-1].second-ans[sz-2].second,arr[i]-ans[sz-2].second)<=0)sz--;
             ans[sz++]=make_pair(i,arr[i]);
        }
        st=--sz;
        for(int i=n-1;i>=0;i--){
            if(vis[i])continue;
            while(sz-st>=2&&cross(ans[sz-1].second-ans[sz-2].second,arr[i]-ans[sz-2].second)<=0)sz--;
            ans[sz++]=make_pair(i,arr[i]);
        }
        int ret=0;
        for(int i=0;i<sz;i++){
            vis[ans[i].first]=1;
        }
        for(int i=0;i<n;i++){
            if(vis[i])continue;
             ret++;
        }
        return ret;

}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }
    sort(arr,arr+n);
    int ans=0;
    int cnt=n;
    while(cnt>2){
         cnt=modify();
        ans++;
    }
    printf("%d",ans);

    



}