/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Feb 06 06:07:45 2018
*   @Idea :  Just Make Floyd For connected componented and usual intersection algorithm..
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
  point operator -(point other){
      return point(x-other.x,y-other.y);
  }
  inline bool operator ==(point other){
      return x==other.x&&y==other.y;
  }
};
struct seg{
  point a,b;
};
const int N=15;
seg arr[N];
bool dp[N][N];
double EPS=1e-8;
long long  cross(point &v1,point &v2){
 return  1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
double norm(point v1){
  return sqrt((v1.x*v1.x)+(v1.y*v1.y));
}
int ccw(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    if(cross(v1,v2) >EPS)return 1;
    if(cross(v1,v2) <-EPS)return -1;
    if(v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
    if(norm(v1) < norm(v2)-EPS)return 1;
    return 0;
}
bool Inter(point &a,point &b,point &c,point &d){
     point v1=b-a;
     point v2=d-c;
     bool f1=(a==b),f2=(c==d);
     if(f1&&f2)return a==c;
     if(f1)return ccw(c,d,a)==0;
     if(f2)return ccw(a,b,c)==0;
     return ccw(a,b,c) * ccw(a,b,d)<=0&&
            ccw(c,d,a) * ccw(c,d,b)<=0;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
     while(t--){
         int n;
         scanf("%d",&n);
         memset(dp,0,sizeof(dp));
         for(int i=0;i<n;i++){
           scanf("%d %d %d %d",&arr[i].a.x,&arr[i].a.y,&arr[i].b.x,&arr[i].b.y);
         }
         for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
              dp[i][j]=dp[j][i]=Inter(arr[i].a,arr[i].b,arr[j].a,arr[j].b);
           }
           dp[i][i]=1;
         }
         for(int k=0;k<n;k++){
           for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
               dp[i][j]|=(dp[i][k]&dp[k][j]);
             }
           }
         }
         int x,y;
         while(scanf("%d %d",&x,&y),(x+y)){
            puts((dp[x-1][y-1])?"CONNECTED":"NOT CONNECTED");
         }
         if(t)puts("");
     }

}