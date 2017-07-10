/*
*   target : get the thief postion of each step if it possible
*      sol :  First we must play in 3 dimenions time-width-height so we first Put all input innear rectangle by lock meaning the thief is not here
*             then we must Try to from end time T  to make path to time -1 by some constraines that the position os (width+-1,heigth+-1,time-1)
*             is not locked or out of rectangle  to avoid useless state then after initiaze all avaible way like named it back
*             from Time 1 now try to get path to T if it's  possible go throw anyone has back to T ...then determine the answer trivial now..
*      Corner Case : he Can still stand in Same position in time+1 :)
*
*
*
*/




#include <bits/stdc++.h>
using namespace std;
const int N=105;
#define lock 0
#define unlock 1
#define back 2
int dp[N][N][N];
int _x[]={0,0,1,-1,0};
int _y[]={1,-1,0,0,0};
int w,h,T,n;
bool check(int x,int y){
   return x>0&&y>0&&x<=w&&y<=h; 
}
void dfs1(int t,int x,int y){
      if(t==1||dp[t][x][y]==back){
             dp[t][x][y]=back;
             return;
      }
      for(int i=0;i<5;i++){
         int xx=x+_x[i],yy=y+_y[i];
         if(check(xx,yy)==0||dp[t-1][xx][yy]==lock)continue;
         dp[t][x][y]=back;
         dfs1(t-1,xx,yy);
      }
}
void dfs2(int t,int x,int y){
       if(t==T||dp[t][x][y]==unlock){
           dp[t][x][y]=unlock;
           return;
       }
       for(int i=0;i<5;i++){
           int xx=x+_x[i],yy=y+_y[i];
           if(check(xx,yy)==0||dp[t+1][xx][yy]==lock)continue;
           if(dp[t+1][xx][yy]==back||dp[t+1][xx][yy]==unlock){
                   dp[t][x][y]=unlock;
                   dfs2(t+1,xx,yy);
           }
       }
}
int main(){
    int cas=1;
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
    while(scanf("%d %d %d",&w,&h,&T),(w||T||h)){
          memset(dp,-1,sizeof(dp));
          scanf("%d",&n);
          for(int i=0,t,x,y,xx,yy;i<n;i++){
              scanf("%d %d %d %d %d",&t,&x,&y,&xx,&yy);
              for(int j=x;j<=xx;j++){
                  for(int k=y;k<=yy;k++){
                     dp[t][j][k]=lock;
                  }
              }
          }
             for(int i=1;i<=w;i++){
                for(int j=1;j<=h;j++){
                    if(dp[T][i][j]!=lock){
                       dfs1(T,i,j);
                    }
                }
             }
             for(int i=1;i<=w;i++){
                for(int j=1;j<=h;j++){
                   if(dp[1][i][j]==back)dfs2(1,i,j);
                }
             }
             printf("Robbery #%d:\n", cas++);
             bool flag=0;
             for(int i=1;i<=T;i++){
                 int cnt=0,ansi=0,ansj=0;
                 for(int j=1;j<=w;j++){
                     for(int k=1;k<=h;k++){
                        if(dp[i][j][k]==unlock){
                           cnt++,ansi=j,ansj=k;
                        } 
                     }
                 }
                 if(cnt==0){
                       puts("The robber has escaped.");
                    flag=1;
                    break;
                 }
                else if(cnt==1){
                    printf("Time step %d: The robber has been at %d,%d.\n", i, ansi, ansj);
                    flag=1;
                 }
             }
             if(!flag){
                 puts("Nothing known.");
             }
             puts("");
    }
}


