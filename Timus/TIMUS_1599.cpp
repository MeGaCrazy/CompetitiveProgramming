/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Mar 09 01:41:32 2018
*   @Idea :  Just make Winding number algorithm and if + direction cnt++ ,- direction cnt--
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
};
int n;
const int N=5005;
point arr[N];
double EPS=1e-5;
long long dot(point v1,point v2){
   return 1ll*v1.x*v2.x+1ll*v1.y*v2.y;
}
long long cross(point v1,point v2){
   return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
double norm(point &v){
   return sqrt(((double)v.x*v.x)+((double)v.y*v.y));
}
int ccw(point &a,point &b,point &c){
  point v1=b-a;
  point v2=c-a;
  if(cross(v1,v2) >0)return 1;
  if(cross(v1,v2) <0)return -1;
  if(v1.x*v2.x <0 || v1.y*v2.y < 0)return -1;
  if(dot(v1,v1) < dot(v2,v2) )return 1;
//  if(norm(v1) < norm(v2) -EPS)return 1;
  return 0;

}
int solve(point &pt){
    int cnt=0;
    for(int i=0;i<n;i++){
        point cur=arr[i];
        point nxt=arr[i+1];
        point v1=nxt-cur;
        point v2=pt-cur;
        if(cur.y <= pt.y ){
            if(nxt.y > pt.y && cross(v1,v2)>0)cnt++;
        }else{
            if(nxt.y <= pt.y && cross(v1,v2)<0)cnt--;
        }
    }
    return cnt;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
  
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d %d",&arr[i].x,&arr[i].y);
    }
    int q;
    scanf("%d",&q);
    arr[n]=arr[0];
    while(q--){
      int x,y;
      scanf("%d %d",&x,&y);
      point pt=point(x,y);
      bool ok=1;
      for(int i=0;i<n;i++){
        if(!cross(arr[i] - pt, arr[i+1] - pt) && dot(pt - arr[i], arr[i+1] - arr[i]) >= 0 && dot(pt - arr[i+1], arr[i] - arr[i+1]) >= 0){
        
          ok=0;
          break;
        }
      }
      if(!ok){
        puts("EDGE");
        continue;
      }
      printf("%d\n",solve(pt));
    }




}