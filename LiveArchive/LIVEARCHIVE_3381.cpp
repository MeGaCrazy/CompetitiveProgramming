/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Feb 26 15:32:39 2018
*   @Idea :   Just Easily Check Same intersectionSegment algorithm .. But ccw <0 not <=0 so statisfy that no point on other...
*             and using dfs Check path from x=0 to x=n  :)
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
int n,m;
const int N=55;
int color[N][N];
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
  seg(point a=point(),point b=point()):a(a),b(b){}
};
bool valid(int x,int y){
   return 0<=x&&x<=n&&0<=y&&y<=n;
}
long long cross(point &v1,point &v2){
   return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
}
long long norm(point &v1){
    return v1.x*v1.x+v1.y*v1.y;
}
int ccw(point a,point b,point c){
    point v1=b-a;
    point v2=c-a;
    if(cross(v1,v2) >0)return 1;
    if(cross(v1,v2) <0)return -1;
    if(v1.x*v2.x <0 || v1.y*v2.y <0)return -1;
    if(norm(v1) < norm(v2) )return 1;
    return 0;
}
bool Inter(point  &a,point &b,point &c,point d){
   bool f1=(b==a),f2=(c==d);
   if(f1&&f2)return c==a;
   if(f1) return ccw(c,d,a)==0;
   if(f2) return ccw(a,b,d)==0;
   return ccw(a,b,c)*ccw(a,b,d)<0&&
          ccw(c,d,a)*ccw(c,d,b)<0;
}
vector<point>adj[N][N];
bool visit[N][N];
int dfs(int x,int y){
      visit[x][y]=1;
      if(x==n)return 1;
      for(int i=0;i<(int)adj[x][y].size();i++){
          point cur=adj[x][y][i];
          if(!visit[cur.x][cur.y]){
             if(dfs(cur.x,cur.y))return 1;
          }
      }
      return 0;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif

     while(scanf("%d %d",&n,&m),(n+m)){
        memset(adj,0,sizeof(adj));
        vector<seg>ss;
        memset(color,-1,sizeof(color));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=m;i++){
           int idx=(i%2);
           point cur;
           scanf("%d %d",&cur.x,&cur.y);
           color[cur.x][cur.y]=idx;
           for(int j=0;j<8;j++){
              int nx=cur.x+dx[j],ny=cur.y+dy[j];
              if(valid(nx,ny)&&color[nx][ny]==idx){
                  bool f=1;
                  for(seg s: ss){
                     if(Inter(s.a,s.b,cur,point(nx,ny))){
                       f=0;
                       break;
                     }
                  }
                  if(f){
                   ss.push_back(seg(cur,point(nx,ny)));
                   if(idx){
                      adj[cur.x][cur.y].push_back(point(nx,ny));
                      adj[nx][ny].push_back(cur);
                   }
                 }
              }
           }
        }
        bool f=0;
        for(int i=0;i<=n;i++){
            if(dfs(0,i)){
              f=1;
              break;
            }
        }
        if(f){
           printf("yes\n");
        }else{
           printf("no\n");
        }
     
     }




}